class Solution {
public:
      int uniq(int i , int j ,int m , int n, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        //if I can go down (not getting out of bound if i go donw) than go down
        if( i+1 < m){
            ans+= uniq(i+1,j,m,n,dp);
        }

//if I can go right , (not getting out of bound if I go right) than go right
        if(j+1 < n){
            ans+= uniq(i,j+1,m,n,dp);
        }

        return dp[i][j]= ans;
      }
    int uniquePaths(int m, int n) {
        //we dont take visited array as as there is no chances of coming back to parent as we move only down and right not top and left i.e, form where we come

        //
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return uniq(0,0,m,n,dp);
    }
};