class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> ans;

         for(int i=0;i<nums.size();i++){
            int val=abs(nums[i]);

            if(nums[val-1]>0){
                nums[val-1]=-nums[val-1];
            }else{
                ans.push_back(val);
            }

         }
         return ans;
    }
};