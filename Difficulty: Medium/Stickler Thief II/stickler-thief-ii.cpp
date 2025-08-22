class Solution {
  public:
  
    int topDown (int start , int n , vector<int>& arr,vector<int>& dp){
        if(n==start) return arr[start];
        
        if(n==start+1){
            return max(arr[start],arr[start+1]);
        }
        
        if(dp[n]!=-1) return dp[n];
        return dp[n] = max (arr[n] + topDown(start,n-2,arr,dp),topDown(start,n-1,arr,dp));
    }
    int maxValue(vector<int>& arr) {
        // your code here
        
        int n= arr.size();
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        
        vector<int> dp1 (n,-1);
        vector<int> dp2 (n,-1);
        int ans1= topDown(0,n-2,arr,dp1);
         
        int ans2=topDown(1,n-1,arr,dp2);
        
        return max(ans1,ans2);
        
    }
};
