//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
     int row[4]={1,-1,0,0};
   int col[4]={0,0,1,-1};
   

   bool valid(int i,int j,int n){
       return  i>=0 && i<n && j>=0 && j<n;
   }
   
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //we don't have to wriiten the shoretst path or shoretst distance
        //we just have to return that whether we can reach froms src to target true or flase
        //so we can use either bfs or dfs , both will work
        //we just traverse form soruce and if target reached return true
        //neighbours will be vertices at left,top,bottom,right of node
        
        //we will not use extra 2d arr for visit mark so when we push neighbour in quue we mark there value in grid matrix to 0 menas now they can't be visited as they already get visited
       
//       A value of cell 1 means Source.
// A value of cell 2 means Destination.
//?so first find source location and target location
int n=grid.size();
int src_r,src_c;

for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
    if(grid[i][j]==1) {
        src_r=i;
        src_c=j;
        break;
    }
  
}

//src can't be targ as given that cell with 1 is src and cell with value 2 is target
//a cell can't have both 1 and 2 vlaue in it so src can't be dest 
//so don't apply if condition to check if src and target same return 0

       queue<pair<int,int>> q ;
       q.push({src_r,src_c});
       grid[src_r][src_c]=0;//mark src as wall
       
       while(!q.empty()){
           int i=q.front().first;
           int j=q.front().second;
           q.pop();
           
           //visit neighbour atmost 4 valid neighbour
           for(int k=0;k<4;k++){
               int new_i=i+row[k];
               int new_j=j+col[k];
               
               if(valid(new_i,new_j,n) && grid[new_i][new_j]!=0){
                   if(grid[new_i][new_j]==2) return true;//reached target return true
                   
                   grid[new_i][new_j]=0;//,ark as wall
                   q.push({new_i,new_j});//push in quue
                   
               }
           }
           
       }
       
       return false;
       
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends