class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
     int start,end;
     start=end=0;
     int len=INT_MIN;

     unordered_map<int,int>mp;
     bool good=true;

     while(end<nums.size()){

        while(end<nums.size() && good){
            mp[nums[end]]++;
            if(mp[nums[end]]<=k){
                len=max(len,end-start+1);
            }else{
                good=false;
            }
            end++;
        }

        while(!good && start<=end){
            mp[nums[start]]--;
            if(mp[nums[start]]==k) good=true;
            start++;
        }
     }   
     return len;
    }
};