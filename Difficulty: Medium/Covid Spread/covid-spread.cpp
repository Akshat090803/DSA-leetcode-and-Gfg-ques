//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int row[4]={-1,1,0,0};//top down left right
   int col[4]={0,0,-1,1};//top down left right
   int c;
   int r;
   
   //to check if we are not going out of bound 
   bool valid(int x,int y){
       return x>=0 && x<r && y>=0 && y<c;
   }
   
    int helpaterp(vector<vector<int>> hospital)
    {
        r=hospital.size();
        c=hospital[0].size();
        
        queue<pair<int,int>> q; // in pair =><row,col> 
        
        //initially push location of all ele whos have corona
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(hospital[i][j]==2) q.push(make_pair(i,j));
        }
        
        int timer=0; //count the time
        //run while queue not empty as queu not empty menas theare are posiibiliyty of spreading corona
        while(!q.empty()){
            timer++;
            int curr_patient=q.size();
            //curr_patient will tell for time t , how many patient are there who can spread corina
            while(curr_patient--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                //as there are 4 direction top,down left and right so run loop for 4 times
                for(int k=0;k<4;k++){
                    //if they are valid person to get infected than infect them and push in queue
                    if(valid(i+row[k] , j+col[k]) && hospital[i+row[k]][j+col[k]]==1){
                        hospital[i+row[k]][j+col[k]]=2; //mark uninfected person corona infected
                        q.push(make_pair(i+row[k] , j+col[k])); //push new patient in queue
                    }
                }
                
            }
        }
        
        //check corona spread to all successfully or someone left
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(hospital[i][j]==1) return -1;
        }
        
        return timer ? timer-1 : 0;
        
        //we return timer-1 and not timer beacuse last round patient are not able to spread corona firther more thats why queue become empty 
        //as they did,t spread corina , there tiem will be decucted as we are updatind time as the first step in loop so timer-1
        //we return 0 for matrix look like this
        // {
        //     0,0,0
        //     0,0,0
        // }
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends