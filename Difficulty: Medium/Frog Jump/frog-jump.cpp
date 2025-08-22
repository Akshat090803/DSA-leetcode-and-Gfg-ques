
class Solution {
  public:
   int minC (int n , vector<int>& height,vector<int>&dp ){
    //   if(n==0) return 0; // because at n=0 , we dont need any distance to reach n=0 ,as frog is already at n=0
       //this if condition already handled at initilaization of dp arr
       if(dp[n]!=-1) return dp[n];
       
       int way1= abs(height[n]-height[n-1]) + minC(n-1 , height , dp);
       int way2=  abs(height[n]-height[n-2]) + minC(n-2 , height , dp);
       
       
       
       return dp[n]= min(way1,way2);
   }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
         
        if(n==1) return 0;  // because at n=0 , we dont need any distance to reach n=0 ,as frog is already at n=0
        if (n==2) return abs(height[0] - height[1]);
        vector<int>dp (n,-1);
        dp[0]=0; // because at n=0 , we dont need any cost to reach n=0 ,as frog is already at n=0
        dp[1]=abs(height[1]-height[0]);
        
        return minC(n-1 , height , dp);
        
    }
};