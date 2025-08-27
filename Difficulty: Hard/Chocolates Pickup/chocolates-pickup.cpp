class Solution {
  public:
  
    int calculate(int i , int j1 , int j2 , int n , int m ,vector<vector<int>>& grid ,  vector<vector<vector<int>>>&dp){
        
        if(i==n-1) {
            if(j1==j2) return grid[i][j1] ; // or grid[i][j2];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        //checking every 9 possible way ,they move simultaneously to next row 
        //for each move of robot1 in cell of next row (-1 , 0 , 1)  robot 2 can move to any cell of next row (-1 , 0 ,1)
        //that if robot 1 goes to left diag of next row , robot2 can go to left diag or right diag or just down cell of next row
        //simialrly when robot 1 goes right diag and down
        //this way we can check all possible 9 permutation/combination
        int max_=INT_MIN;
        for(int dj1 = -1 ; dj1<=1 ; dj1++)
        for(int dj2=-1 ; dj2 <=1; dj2++){
            //if we will not go out of bound  make call
              if((j1 + dj1)>=0 && (j1+dj1)<m && (j2+dj2)>=0 && (j2+dj2)<m){
                  //store max out of all 9 ways
                  max_= max(max_ , calculate(i+1 , j1+dj1 , j2+dj2 , n ,m , grid , dp)); 
              }
        }
        
        if(j1==j2) return dp[i][j1][j2] = grid[i][j1] + max_;
        else return dp[i][j1][j2]= grid[i][j1] + grid[i][j2] + max_;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        //we need 3d dp for this as we need to store result at row , j1 , j2
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m,-1)));
        return calculate(0 , 0 , m-1 , n , m , grid , dp);
        
    }
};