// User function Template for C++

class Solution {
  public:
    int maxProfit(int i , int capacity ,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp ){
        
        if(i==wt.size() || capacity==0) return 0;
        
        if(dp[i][capacity]!=-1) return dp[i][capacity];
        int take=0,notTake=0;
        
        if(wt[i] <= capacity){
            //as we can take item any no. of time , dont upgrade i to i+1 when taking ith item as this way we can take this infinite number of time
            take = val[i] + maxProfit(i ,capacity - wt[i] , val,wt,dp );
        }
        
        notTake = 0 + maxProfit(i+1,capacity , val , wt,dp);
        
        return dp[i][capacity] = max(take , notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(capacity+1,-1));
         return maxProfit(0,capacity , val , wt,dp);
    }
};