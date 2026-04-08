class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          unordered_set<int>s;

          int repeated=0;
          for(int x:nums){
            if(s.find(x)==s.end()) s.insert(x);
            else {
                repeated=x;
                break;
            };
          }
          return repeated;
    }
};