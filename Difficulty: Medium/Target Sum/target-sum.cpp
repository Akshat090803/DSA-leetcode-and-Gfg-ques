//Back-end complete function Template for C++

class Solution {
  public:
   long long  countSub(int i , long long s1 , long long s2 , int d , vector<int>&arr,vector<unordered_map<int,int>>&dp){
     
        if(i==arr.size()){
            if( s1-s2 == d) return 1;
            else return 0;
        }
        
        if(dp[i].count(s1)) return dp[i][s1];
        
        long long include=countSub(i+1 , s1+arr[i] , s2-arr[i] ,d,arr,dp);
        long long exclude=countSub(i+1 , s1 , s2 ,d,arr,dp);
        
        return dp[i][s1] = include + exclude;
   }
    long long findTargetSumWays(int n, vector<int>& nums, int target) {
        // Your code here
        long long total=0;
        for(auto x: nums) total+=x;
        
        vector<unordered_map<int,int>>dp(n); //
        //we can use vector<vector<int>>dp(arr.size() , vector<int>(total+1, -1));
        
        return countSub( 0 ,0 ,total , target , nums,dp);
    }
};