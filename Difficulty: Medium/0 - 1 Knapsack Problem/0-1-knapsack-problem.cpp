class Solution {
  public:
    
    int result(int i ,  int W , vector<int> &val, vector<int> &wt,  vector<vector<int>>&dp){
         
         if(W==0 || i==val.size()) return 0;
         
        //  if(dp[i].count(currSum)) return dp[i][currSum];
         if(dp[i][W]!=-1) return dp[i][W];
         
         
         int include=0;
         int exclude=0;
         
         //include 
         //include only when bag has capacity to store
         if(W >= wt[i]){
            include =  val[i]+ result(i+1  , W - wt[i] , val , wt , dp);
         }
         
         //exclude
          exclude =   result(i+1 , W  , val , wt , dp);
          
          return dp[i][W] = max(include , exclude);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        //  vector<unordered_map<int,int>>dp(val.size()); //
        //instead of vector of unordered_map we can use 2d vector as well
        //we can use vector<vector<int>>dp(val.size() , vector<int>(totalSum+1, -1)); as for column of 2d arr max value/index can be totalSum if we keep store info for (i,currSum)
        //if we use (i, Remainig Wt) for memoization , than dp array can be vector<vector<int>>dp(val.size() , vector<int>(W+1, -1)); as for col of 2d arr max W /ind can be W 
        //vector of unordered map will same for both (i,sum) or (i,wt)
        vector<vector<int>> dp(val.size()+1, vector<int>(W+1, -1));
        return result(0,W,val,wt , dp);
    }
};