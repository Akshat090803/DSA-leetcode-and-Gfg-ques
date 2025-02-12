//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     
     int rows[8] ={-1,-1,-1,1,1,1,0,0};//for all 8 direction
     int cols[8] ={-1,0,1,-1,0,1,-1,1};//for all 8 directions
     int r;
     int c;
     
     bool valid(int i,int j){
         return i>=0 && i< r && j>=0 && j<c;
     }
     
    int numIslands(vector<vector<char>>& grid) {
        
        r=grid.size();
        c=grid[0].size();
        
        //!we are using BFS here
        
        queue<pair<int,int>>q;   //<row,col>
        int count=0;
        //check for the 1
        //if 1 found start building  island from that 1
        //mark 1 as -1 which indicates that they are visited i.e, they are already part of an island
    
        for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
            //1 found so start building island
            if(grid[i][j]=='1'){
                q.push(make_pair(i,j));
                grid[i][j]='0'; //mark visit as we are ignoring 0 so for visited also take 0
                // grid[i][j]='-1'; //don't mark -1 as grid is  char arr and -1 is not treated as a char.It is created as a striing of len 2
                count++;
               
                //start connecting adjacent lands
                while(!q.empty()){
                    int new_i=q.front().first;
                    int new_j=q.front().second;
                    q.pop();
                    
                    //check all 8 direction 
                    for(int k=0;k<8;k++){
                        
                        if(valid(new_i+rows[k],new_j+cols[k]) && grid[new_i+rows[k]][new_j+cols[k]]=='1'){
                            grid[new_i+rows[k]][new_j+cols[k]]='0';//mark visited
                            q.push(make_pair(new_i+rows[k],new_j+cols[k]));
                            //push new land in queue so that we can add its adjacecnt lands also
                        }
                    }
                }
            }
        }
        }
       
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends