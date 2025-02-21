//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int row[4]={1,-1,0,0};
   int col[4]={0,0,1,-1};
   
   int n,m;
   bool valid(int i,int j){
       return  i>=0 && i<n && j>=0 && j<m;
   }
   
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        //if try to make graph from the given matirce u will see it is like shoretst path in unidrected unweighted graph 
        //so we use BFS to solve it
        //but in this neighbours of node will be its top,left,right and bottom
        //intead of using 2d matrix for tracking visiting we will repalce 1 by 0 in matirx A itself after pushing them in queueu.
        //As 0 indicates we can't visit them thats why
        n=N;
        m=M;
        //!Time -> O(n*m) worst case we visit all indexes of 2d mat of n*m
        //!space-> O (min(n,m))
        
        //edge case 
        if(A[0][0]==0) return -1; //as if we can't visit the source than how we will reach dest
        
        if(X==0 && Y==0 ) return 0; //if source and destination is same
        
        // way-1 taking 3 things in a pair i,j,step
        queue<pair<int,pair<int,int>>>q; //{ i , {j , step}
        q.push({0,{0,0}});//push for the source 
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second.first;
            int step=q.front().second.second;
            q.pop();
            
            //neighbours 
            for(int k=0;k<4;k++){
                int new_i=i+row[k];
                int new_j=j+col[k];
                
               
                
                if(valid(new_i,new_j) && A[new_i][new_j]==1){
                    
                     if(new_i==X && new_j==Y) return step+1;//ans found
                     
                    A[new_i][new_j]=0;//mark visited
                    int new_step=step+1;
                    q.push({new_i,{new_j,new_step}});
                }
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends