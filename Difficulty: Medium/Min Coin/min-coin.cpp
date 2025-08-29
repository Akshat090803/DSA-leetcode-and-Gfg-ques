class Solution {
  public:
//   INFO
// General coin set → greedy may fail → use DP. (This problem)

// Special coin systems (canonical like Indian currency, US currency) → greedy is optimal.
//see this problem https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

    int coins(int i,int amount , vector<int> nums, vector<vector<int>>&dp){
        if(amount ==0) return 0;
       if(i==nums.size() || amount < 0) return INT_MAX;
        
        if(dp[i][amount]!=-1)return dp[i][amount];
        
            //dont take whole amount that nums[i] can fill , just take one at time
            //i.e dont do amount/nums[i] just take nums[i] one at a time as if we take whole time i.e, amount/nums[i] ths way we become greedy and get wrong ans
            
            int take = coins(i,amount-nums[i],nums,dp); //dont increase i to i+1 
            if(take!=INT_MAX) take++; //increase coin count by 1
            
        
        
        int exclude=coins(i+1,amount,nums,dp);
        
        return dp[i][amount]=min(take,exclude);
    }
    int MinCoin(vector<int> nums, int amount) {
        
        // vector<vector<int>>dp(nums.size(),vector<int>(amount+1,-1));
        // int ans=coins(0,amount,nums,dp);
        // return (ans==INT_MAX) ? -1 : ans;
        
        //!Bottom Up
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        
        // Base case: amount = 0 requires 0 coins
        //in top d base case was  if(amount ==0) return 0;
        //so when amount =0 its value willbe 0
    
        for(int i=0;i<n;i++) dp[i][0]=0;
        
        //fill first row seperately
        //dont start form x=0 as in above for loop for all 0 amount of each row value will be 0
         for (int x = 1; x <= amount; x++) {
        if (x % nums[0] == 0) dp[0][x] = x / nums[0];
        }
        
        // Process remaining coins
        for (int i = 1; i < n; i++) {
        for (int x = 1; x <= amount; x++) {
            int exclude = dp[i - 1][x];  // don’t take coin[i]
            int include = 1e9;
            if (nums[i] <= x && dp[i][x - nums[i]] != 1e9) {
                include = 1 + dp[i][x - nums[i]];  // take nums[i] (unbounded)
            }
            dp[i][x] = min(include, exclude);
        }
    }

    int ans = dp[n - 1][amount];
    return (ans >= 1e9 ? -1 : ans);
    }
};