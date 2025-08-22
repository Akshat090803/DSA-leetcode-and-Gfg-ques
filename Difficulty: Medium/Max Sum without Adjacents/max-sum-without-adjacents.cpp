// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int maxSum(int n, vector<int>& arr , vector<int>& dp){
        if(n==0) return arr[0];
        if(n==1) {
            return max(arr[0],arr[1]);
        }
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = max(arr[n] + maxSum(n-2,arr,dp) , maxSum(n-1,arr,dp));
    }
    int findMaxSum(vector<int>& arr) {
        // 
        
        int n=arr.size();
        
        vector<int>dp(n,-1);
        
        return maxSum(n-1,arr,dp);
    }
};