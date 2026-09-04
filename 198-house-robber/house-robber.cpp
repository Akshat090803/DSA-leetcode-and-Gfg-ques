class Solution {
public:
    int robHelper(vector<int>& nums,int n , int i,vector<int>& dp ){
        if(i>=n) return 0;
         
         if(dp[i]!=-1) return dp[i];
         //rob current and then rob next adjacent i.e i+2
         int amt = nums[i] + robHelper(nums,n,i+2,dp);
         //dont rob current rob next i.e i+1
         int amt2 = robHelper(nums,n,i+1,dp);

         return dp[i]= max(amt,amt2);


    }
    int rob(vector<int>& nums) {
        int n = nums.size();
             vector<int> dp (n+1,-1);
        int ans = robHelper(nums,n,0,dp);
   
        return ans;
    }
};