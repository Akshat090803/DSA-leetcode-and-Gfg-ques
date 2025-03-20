class Solution {
public:
    int bottom_up(vector<int>& nums) {
        // this is base condiiton 1 when single house is there i.e, i=0
        int n=nums.size();
        if (n == 1)
            return nums[0];
        // whe i=1 (menas two houses)
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
       vector<int> dp(n, -1);
        // intiialize with base case
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        //! Similar to hpuse Robber problem
        //?diffrence is that there is circular arr menas first index connected
        //to last index
        // so we nee dto take care that if we include last index we will not
        // include first index and vice versa
        //?means first index and last index should not included together as they
        //are adjacent(because of circularity) ?so we create two seperate arr
        // fist array will contain elemnets form index 0 to index n-2
        //?(i.em from first ele to second last ele)
        // second array will contain elemnets form index 1 to index n-1
        //?(i.em from second ele to  last ele)
        // find max_rob for both the array sperately (same way we did in house
        // robber problem) then final ans will be max between max_rob of arr`1
        // and arr2 this way we ensure that first and last ele will never be
        // together

        // create two seperate array
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;

        for (int i = 0; i < n - 1; i++) {
            arr1.push_back(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            arr2.push_back(nums[i]);
        }

        //! Dp Bottom up approach
        // if(n==1)
        // return nums[0];

        // if(n==2)
        // return max(nums[0],nums[1]);

        // int arr1_opt=bottom_up(arr1);
        // int arr2_opt=bottom_up(arr2);

        // return max(arr1_opt,arr2_opt);

        //!Dp space optimization
        //?without dp array and arr1 and arr2 are also not used
        //we will take prev1 and prev2 
        //and curr1 and curr2 (curr1 for arr1 ) and (curr2 for arr2)
        //?value initilaization of prev1 and prev2 for arr1 and arr2 will be different
       if(n==1)
        return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);
         
         //!for  (ind=0 to ind= n-2 (second last ele))
        int prev1=max(nums[1],nums[0]);
        int prev2=nums[0];
        int curr1=prev1; //(we iniitialse curr1 with prev1 instead of 0 becuse if size of nums is 3 ,cnsider eg: [2,3,2]  )
        for(int i=2;i<n-1;i++){
            curr1=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr1;
        }

         //!for  (ind=1 to ind= n-1 (second ele to  last ele))
         prev1=max(nums[1],nums[2]);
         prev2=nums[1];
         int curr2=prev1;
           for(int i=3;i<n;i++){
            curr2=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr2;
        }
   return max(curr1,curr2);
    }
};