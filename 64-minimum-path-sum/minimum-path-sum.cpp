class Solution {
public:

//top down
int minPath (int i , int j , int m , int n ,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i==m-1 && j==n-1 ) return grid[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];

    int min_=INT_MAX; 

//if we can go down , go down 
    if(i+1 < m ){
        min_ = min(min_ , minPath(i+1 , j , m ,n , grid,dp));
    }
//if we can go right , go right;
    if(j+1 < n){
        min_=min(min_ , minPath(i,j+1 , m , n , grid , dp));
    }

    return dp[i][j] = grid[i][j] + min_;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // if(m==1 && n==1) return grid[0][0]; //this will also gets handle in the base case of minPath func (top down dp)

        // vector<vector<int>>dp(m , vector<int>(n,-1));
        // return minPath(0,0,m,n,grid , dp);

        //!Bottom Up
        if(m==1 && n==1) return grid[0][0];
         vector<vector<int>>dp(m , vector<int>(n,INT_MAX));

         dp[0][0]= grid[0][0];

         for(int i=0;i<m;i++)
         for(int j=0;j<n;j++){
            int min_=INT_MAX;

            if(i>0 && dp[i-1][j]!=INT_MAX){
                dp[i][j]=min(dp[i][j] , dp[i-1][j]+grid[i][j]);
            }

            if(j>0 && dp[i][j-1]!=INT_MAX){
                dp[i][j]=min(dp[i][j] , dp[i][j-1]+grid[i][j]);
            }

            
         }

         return dp[m-1][n-1];
    }
};