class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
       vector<int>counts(101,0); //we follow 1 based indexing so instead of size 100 ,we use 101
       for(auto x:nums){
               counts[x]++;
               if(counts[x]>2) return false;
       }
       return true;
    }
};