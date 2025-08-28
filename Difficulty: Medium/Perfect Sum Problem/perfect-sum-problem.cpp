class Solution {
  public:
    
    int countSub(int i , int currSum ,int n ,int target,vector<int>& arr, vector<vector<int>>&dp ){
      
        if(i==n ){
           if(currSum==target) return 1;
           else return 0;
        }
        
        if(currSum > target) return 0;
        
        if(dp[i][currSum]!=-1) return dp[i][currSum];
       
        //include
        int include = countSub(i+1 , currSum+arr[i] ,n, target , arr,dp);
        
        //exclude;
        int exclude = countSub(i+1 , currSum ,n, target , arr , dp);
        
        return dp[i][currSum] = include + exclude;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        vector<vector<int>>dp(n,vector<int>(target+1 , -1)); 
        return countSub(0,0,n,target,arr , dp);
    }
};