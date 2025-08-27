class Solution {
  public:
    //  bool check(int i ,int  currSum, vector<int>& arr, int sum ,  vector<vector<int>>&dp){
    //       if(currSum == sum ) return 1;
    //      if(i >=arr.size() || currSum > sum) return 0;
         
        
         
    //     // include arr[i] OR skip it
    // bool include = check(i+1, currSum + arr[i], arr, sum, dp);
    // bool exclude = check(i+1, currSum, arr, sum, dp);
    
    // return dp[i][currSum] = include || exclude;
         
    //  }
    // bool isSubsetSum(vector<int>& arr, int sum) {
    //     // code here
    //     int n=arr.size();
    //     //memoization don't depend on index i onky it depends on combination of index i and currSum at that i 
    //     vector<vector<int>>dp(n , vector<int>(sum+1 , -1));
    //     return check(0,0,arr,sum,dp);
        
       
    // }
    bool check(int i, int currSum, vector<int>& arr, int sum, vector<vector<int>>& dp) {
    if(currSum == sum) return true;
    if(i >= arr.size() || currSum > sum) return false;
    
    if(dp[i][currSum] != -1) return dp[i][currSum];
    
    // include arr[i] OR skip it
    bool include = check(i+1, currSum + arr[i], arr, sum, dp);
    bool exclude = check(i+1, currSum, arr, sum, dp);
    
    return dp[i][currSum] = include || exclude;
}

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum+1, -1)); // state: index + currSum
    return check(0, 0, arr, sum, dp);
}
};