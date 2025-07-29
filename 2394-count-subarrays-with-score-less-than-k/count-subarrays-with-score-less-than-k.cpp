class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        //simalar to subarr product less than k but little variation
        //?https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/
        //in subarray product less than k we were maintinaing product variaable but here we will maintain sum , score variable
        //jb tk score km h hm window size icrease krnege aur sum+=arr[end]
        //agr score jyada ho jata he to ,window reduce krenge aur sum-=arr[start] aur socre bhi km krnege
        int len=1;
        long long sum=0,score=0;
        long long count=0,start=0,end=0;

        while(end<nums.size()){
            sum+=nums[end];
            score=sum*len; // 1+(end-start) will give length of window

            while(score>=k && start<=end){
                sum-=nums[start]; //reduce the sum as arr[start] will remove from window
                start++;  //start++ to reduce length
                //calcualted updates score
                len--;
                score=sum*len; //1+end-start gives new length of window
                
            }

            count+=len; //size of windpw will tells about how many subarr
            end++;
            len++;
        }
        return count;
    }
};