//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int rows[4]={-1,1,0,0};
  int cols[4]={0,0,-1,1};
  int r;
  int c;
  
  bool valid(int i,int j){
      return i>=0 && i<r && j>=0 && j<c;
  }
  
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        //logic
        //search for O's on boundry
        //make group from O starting from boundary
        //mark the O's coming in that set to 'T' or any other char excppt O or x
        
        //now all the remaming O's can be converted into X
        //so after completing all process run a loop in which we convert "T" back to O
        // and  remaing O's to X
        //why we make set from O's starting from boundary because set starting from boundary or even single O present at boundary can' be repalce by X because they never be surrounded By 'X' from all 4 sides
        //hence group forming from that O will also not be surrouunded by X from all sided 
        
        //?We sue BFS here
        r=mat.size();
        c=mat[0].size();
        queue<pair<int,int>>q;
        
        //!here we are only pushing O's present at boundary
        //we will make their group later
        
        //push O's from top boundary in queue
        //in top boundary i will 0 but j change
        for(int j=0;j<c;j++){
            if(mat[0][j]=='O') {
                q.push({0,j});
                mat[0][j]='T';
            }
        }
        
        //push O's from Left boundary in queue
        //in left boundary i will change but j will 0
        //and i will start form 1 as i=0 already included in top boundary
        for(int i=1;i<r;i++){
            if(mat[i][0]=='O') {
                q.push({i,0});
                mat[i][0]='T';
            }
        }
        
        //push O's from bottom boundary in queue
        //in left boundary i will r-1 but j will change
        //and j will start form 1 as j=0 already included in left boundary
        for(int j=1;j<c;j++){
            if(mat[r-1][j]=='O') {
                q.push({r-1,j});
                mat[r-1][j]='T';
            }
        }
        
        //push O's from Right boundary in queue
        //in Right boundary i will change but j will c-1
        //and i will start form 1 as i=0 already included in top boundary and till i<r-1 as r-1 row already icluded in bottom boundary
        for(int i=1;i<r-1;i++){
            if(mat[i][c-1]=='O') {
                q.push({i,c-1});
                mat[i][c-1]='T';
            }
        }
        
        //make group
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            //check in all directio for group
            for(int k=0;k<4;k++){
                if(valid(i+rows[k],j+cols[k]) && mat[i+rows[k]][j+cols[k]]=='O')
                {
                    mat[i+rows[k]][j+cols[k]]='T'; //replace them by 'T'
                    q.push(make_pair(i+rows[k],j+cols[k]));
                }
                
            }
        }
        
        //repaplce T by O and reaminng O by X
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(mat[i][j]=='T') mat[i][j]='O';
            else if(mat[i][j]=='O') mat[i][j]='X';
        }
        
        return mat;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends