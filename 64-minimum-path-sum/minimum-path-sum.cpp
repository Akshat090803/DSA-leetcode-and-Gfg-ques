class Solution {
public:

//top down
int minPath (int i , int j , int m , int n ,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i==m-1 && j==n-1 ) return grid[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    int min_=INT_MAX;

    if(i+1 < m ){
        min_ = min(min_ , minPath(i+1 , j , m ,n , grid,dp));
    }

    if(j+1 < n){
        min_=min(min_ , minPath(i,j+1 , m , n , grid , dp));
    }

    return dp[i][j] = grid[i][j] + min_;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // if(m==1 && n==1) return grid[0][0]; //this will also gets handle in the base case of minPath func (top down dp)

        vector<vector<int>>dp(m , vector<int>(n,-1));
        return minPath(0,0,m,n,grid , dp);
    }
};