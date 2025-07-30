class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int sum=0;
         int len=1;
         int minLen=INT_MAX;
         int start,end;
         start=end=0;
         int n=nums.size();

         while(end<n){
            sum+=nums[end];

//reduce sum and calculate minLength until sum less than target
            while(sum>=target && start<=end){
                 minLen=min(minLen,len);
                 sum-=nums[start];
                 start++;
                 len--;

            }

            end++;
            len++;
         }
   if(minLen==INT_MAX) return 0;
   return minLen;
    }
    
};