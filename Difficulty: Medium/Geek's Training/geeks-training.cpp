
class Solution {
  public:
  
  int maxP (int row , int prev ,vector<vector<int>>& arr , vector<vector<int>>& dp ){
      if (row == arr.size()) return 0;

    if(dp[row][prev+1]!=-1) return dp[row][prev+1];
    int run = 0, fight = 0, learn = 0;

    if (prev != 0)  // can choose run
        run = arr[row][0] + maxP(row+1, 0, arr,dp);

    if (prev != 1)  // can choose fight
        fight = arr[row][1] + maxP(row+1, 1, arr,dp);

    if (prev != 2)  // can choose learn
        learn = arr[row][2] + maxP(row+1, 2, arr,dp);

    return dp[row][prev+1]= max(run, max(fight, learn));
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        
      
        vector<vector<int>>dp(arr.size(),vector<int>(4,-1));
        //start form -1 as no previous task restriction , he has not choosed any atsk
        return maxP(0,-1,arr,dp);
        
    }
};