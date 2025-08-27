class Solution {
  public:
  
     bool check(int i ,int  currSum, vector<int>& arr, int target, vector<vector<int>>&dp ){
          if(currSum == target ) return 1;
         if(i >=arr.size() || currSum > target) return 0;
         
         if(dp[i][currSum] != -1) return dp[i][currSum];
         
        // include arr[i] OR skip it
    bool include = check(i+1, currSum + arr[i], arr, target , dp);
    bool exclude = check(i+1, currSum, arr, target , dp);
    
    return dp[i][currSum]=include || exclude;
         
     }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalSum=0;
        
        for(auto x : arr) totalSum+=x;
        
        // If total sum is odd, can't partition into equal halves
    if(totalSum % 2 != 0) return false;
         
         int target = totalSum/2; 
         vector<vector<int>> dp(n, vector<int>(target+1, -1)); //if sum becomes greater than target we return false  so make arr fof size n , target+1 as we will not get overflow for index where sum>target
        return check(0,0,arr,target , dp);
    }
};