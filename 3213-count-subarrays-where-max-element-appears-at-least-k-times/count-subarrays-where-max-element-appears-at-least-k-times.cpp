class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
         int count=0;

         int start,end;
         start=end=0;
         long long subarr=0;
          int maxEle=INT_MIN;
          for(auto x: nums) maxEle=max(maxEle,x);
         while(end<nums.size()){

            if(nums[end]==maxEle) count++;

            while(count==k){
                subarr+=(nums.size()-end);

                if(nums[start]==maxEle) count--;
                start++;
            }
            
          end++;
         }
         return subarr;
    }
};