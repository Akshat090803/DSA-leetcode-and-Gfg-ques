// User function Template for C++

class Solution {
  public:
     int maxPath(int i , int j , int n , int m ,vector<vector<int>>&mat ,vector<vector<int>>&dp ){
         if(i==n-1) return mat[i][j];
         
         if(dp[i][j]!=-1) return dp[i][j];
         int down=0;
         int left_diag=0;
         int right_diag=0;
         //if  (i can go down)
         if(i+1 < n)
         down = maxPath(i+1,j,n,m,mat,dp);
         
         //if i can go to left down diagonal
         if(i+1 < n && j-1 >= 0)
         left_diag = maxPath(i+1,j-1,n,m,mat,dp);
         
         //if i can go to right down diagonal
         if(i+1 < n && j+1 < m)
         right_diag = maxPath(i+1,j+1,n,m,mat,dp);
         
         return dp[i][j] = mat[i][j] + max(down , max(left_diag , right_diag));
     }
     
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m= mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=INT_MIN;
        for(int j=0;j<m;j++)
        ans=max(ans , maxPath(0,j,n,m,mat,dp));
        
        return ans;
        
        
    }
};