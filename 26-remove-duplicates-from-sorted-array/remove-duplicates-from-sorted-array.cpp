class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write=0;
        int read=0;
        int n=nums.size();
        while(read<n){
            int currNum = nums[read];

            while(read<n && nums[read]==currNum){
                read++;
            }

            nums[write]=currNum;
            write++;
        }
        return write;
    }
};