class Solution {
public:
int countCoins (int i , int n, int amount ,  vector<int>& coins,vector<vector<int>>&dp){
   
   if(amount ==0) return 1;
   if(i==n || amount<0) return 0;
    
    if(dp[i][amount]!=-1) return dp[i][amount];
    
   int take = 0;
   if(coins[i] <= amount){
    take = countCoins(i,n,amount-coins[i] , coins,dp); //take the same coin once again. See we are not increasing i to i+1 in func call
   }

   int notTaken = countCoins(i+1,n,amount , coins,dp);

   return dp[i][amount]= take + notTaken;

}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return countCoins(0,n,amount,coins,dp);
    }
};