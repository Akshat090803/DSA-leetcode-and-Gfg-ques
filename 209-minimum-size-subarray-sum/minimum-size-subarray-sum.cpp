class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //we use sliding window
        //we not using map as we have to find subarray whose sum is greater than equal to k .
        //here the condition for if condiition  will be any previous sum which (less than or equal to sum-k) we can't give this codniton in map in map.find() than  what will we find in map as suppose sum-k is 12 and map has  key {4 ,6 8} than all 4,6,8 are smaller than sum-k which to select than .We can give only find any previous sum which is equal to (sum-k)
        //so map will be used to find subarray for exact sum eqaul to k ques as in this we have to look for (sum-k) previous sum only

        int start=0,end=0;
        int sum=0;
        int min_len=INT_MAX; 

        while(end<nums.size()){
            sum+=nums[end];
            
            //while sum is greater than or equal to target , reduce window size to check if there exist smaller length subarr also whose sum is greater than equal to target
            //as all ele in arr is +ve , so if we found any subarray whose sum is greater than eqaul to target, if we increase the window size than eventually sum will increse (as all ele is +ve) so we will not able to find subarray of minmium length as windpow increase
            //so we reduce the window ,to find sub arr of smaller len whose sum is greater than equal to target
            while(sum>=target && start<=end){
                min_len=min(min_len,(1+end-start));
                sum-=nums[start];
                start++;
            }
            end++;
        }

        return (min_len==INT_MAX) ? 0 : min_len;// If there is no such subarray, return 0 instead.

 
    }
};