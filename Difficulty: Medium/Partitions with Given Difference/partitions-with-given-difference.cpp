class Solution {
  public:
   int  countSub(int i , int s1 , int s2 , int d , vector<int>&arr,vector<unordered_map<int,int>>&dp){
        //as we have to count all such subsets we will check after only i==n
        if(i==arr.size()){
            if(s1 >= s2 && s1-s2 == d) return 1;
            else return 0;
        }
        
        if(dp[i].count(s1)) return dp[i][s1];
        
        // s1= currSum s2 = rest ele sum (another subset sum) i.e, total-currSu,
        //insetaf of calculating sum of toher subset at baase case total-s1 we are simulatneously calaculating it here in S2 . We can use first approach as well as
        int include=countSub(i+1 , s1+arr[i] , s2-arr[i] ,d,arr,dp);
        int exclude=countSub(i+1 , s1 , s2 ,d,arr,dp);
        
        return dp[i][s1] = include + exclude;
   }
    int countPartitions(vector<int>& arr, int d) {
        
        int total=0;
        for(auto x: arr) total+=x;
        
        vector<unordered_map<int,int>>dp(arr.size()); //
        //instead of vector of unordered_map we can use 2d vector as well
        //we can use vector<vector<int>>dp(arr.size() , vector<int>(total+1, -1));
        
        return countSub( 0 ,0 ,total , d , arr,dp);
        
    }
};