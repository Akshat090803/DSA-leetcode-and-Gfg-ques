class Solution {
public:
   //!way-1 (recursion)
   //?we will get T.L.E
//    int max_way1(int i,vector<int>&nums){
//     //only one house so we will steal form it
//     if(i==0)
//     return nums[0];

// //we go out of bound that is no such house exist so return 0 we steal 0 money
//     // if(i<0)
//     // return 0;
//  //!the above conditon can also return as
// //if we see recursion tree we see we are getting -ve i when we are at i=1 ; as form i=1 we can steal at i=1 house and skip adjacent and check for i-2 house i.e, 1-2=-1 or we cAN SKip i=1 house and steal from i=0 house 
// //?so we can write base case for i=1 i.e, return max(nums[0],nums[1]+0) ~ max(nums[0],nums[1])
//     //the above conditon can also return as

//     if(i==1){
//         return max(nums[0],nums[1]);
//     }

//     return max(nums[i]+max_way1(i-2,nums) , max_way1(i-1,nums));
//    } 

//-----------------------------------------------------------------
   //!optimise using DP Top Down Approach
     int dp_TopDown(int i,vector<int>&nums,vector<int>&dp){
    //only one house so we will steal form it
    if(i==0)
    return nums[0];

    if(i==1){
        return max(nums[0],nums[1]);
    }

    if(dp[i]!=-1)
    return dp[i];

    return dp[i]=max(nums[i]+dp_TopDown(i-2,nums,dp) , dp_TopDown(i-1,nums,dp));
   } 

    int rob(vector<int>& nums) {
         
         int i=nums.size()-1;
         //T.L.E for way-1 
        //  return max_way1(i,nums);

        //!Dp topdown
        //?size of dp array
        //for nums of size 6 ,the max func call will be of i=size-1
        //so max index for dp arr will be size()-1
        //so simply make dp array of size nums.szie() as last ind wil be size-1
        //? vector<int>dp(nums.size(),-1);
        //? return dp_TopDown(i,nums,dp);

        //!Dp Bottom up approach
        int n=nums.size();
        //this is base condiiton 1 when single house is there i.e, i=0
        if(n==1) 
        return nums[0];
 //whe i=1 (menas two houses)
        if(n==2){
            return  max(nums[0],nums[1]);
        }

        vector<int>dp(n,-1);
//intiialize with base case
dp[0]=nums[0];
dp[1]=max(nums[0],nums[1]);

for(int i=2;i<n;i++){
dp[i]=max(nums[i]+dp[i-2] , dp[i-1]);
}

return dp[n-1];

    }
};