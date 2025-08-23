class Solution {
public:
    int uniq(int i, int j, int m, int n, vector<vector<int>>& grid,
             vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1)
            return 1;

        if(grid[i][j]==1) return 0; 

        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        // if I can go down (not getting out of bound if i go donw) than go down
        if (i + 1 < m) {
            ans += uniq(i + 1, j, m, n,grid, dp);
        }

        // if I can go right , (not getting out of bound if I go right) than go
        // right
        if (j + 1 < n) {
            ans += uniq(i, j + 1, m, n,grid, dp);
        }

        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return uniq(0,0,m,n,obstacleGrid,dp);
    }
};