class Solution {
public:
    
     int  countSub(int i , int s1 , int s2 , int d , vector<int>&arr,vector<unordered_map<int,int>>&dp){
     
        if(i==arr.size()){
            if( s1-s2 == d) return 1;
            else return 0;
        }
        
        if(dp[i].count(s1)) return dp[i][s1];
        
        int include=countSub(i+1 , s1+arr[i] , s2-arr[i] ,d,arr,dp);
        int exclude=countSub(i+1 , s1 , s2 ,d,arr,dp);
        
        return dp[i][s1] = include + exclude;
   }

    int findTargetSumWays(vector<int>& nums, int target) {
        //this can be seen as Partitions with Given Difference probelm GFG https://www.geeksforgeeks.org/problempartitions-with-given-difference1
        //ideally we have to make choice once take +ve sign and once take -ve
        //but if we see if we put sum of +ves in S1 and sum of -Ve in s2 and than and take - common in s2 than it will be like S1 - S2 ==target which was in Partition with given difference problem
        //suppose in [1,1,1,1,1] T=3,  if we take first four ele as +ve and last as -ve than  it will be +1 , +1 , +1 , +1 , -1
        //+1 in s1 s1=4 all 4 +1's in s1 and s2 = -1 ;

        //so s1=4 and s2=-1
        //s1+s2 = 4+(-1)=3 
        //so we will not convert any no. in +ve or -ve just do S1 - S2
        //i.e, S1 has {1,1,1,1} and S2 = {1} so 4-1 = 3

        int total=0;
        for(auto x: nums) total+=x;
        
        vector<unordered_map<int,int>>dp(nums.size()); //
        //we can use vector<vector<int>>dp(arr.size() , vector<int>(total+1, -1));
        
        return countSub( 0 ,0 ,total , target , nums,dp);
 
    }
};