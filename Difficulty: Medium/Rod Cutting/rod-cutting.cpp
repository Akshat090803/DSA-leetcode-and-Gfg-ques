// User function Template for C++

class Solution {
  public:
    int maxProf(int i  , int length , vector<int> &price,vector<vector<int>>&dp){
        if(i == price.size() || length==0) return 0;
        
        if(dp[i][length]!=-1) return dp[i][length];
        int take=0;
        
        // I have take i as 0 based so at i=0 cutt Length will be i+1 i.e, (0+1 = 1)
        if(length >= i+1){
            take = price[i] + maxProf(i , length - (i+1) , price, dp);
            //length - (i+1) as i is 0 based so at i=0 cut length will be 1 , at i=1 cut length will be 2
        }
        
        int notTake = maxProf(i+1,length , price, dp);
        
        return dp[i][length]= max(notTake , take);
    }
    int cutRod(vector<int> &price) {
        // code here
        int length = price.size();
        vector<vector<int>>dp(length,(vector<int>(length + 1, -1)));
        return maxProf(0,length , price , dp);
    }
};