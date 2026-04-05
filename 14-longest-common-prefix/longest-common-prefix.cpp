class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;
   
        string ref = strs[0];
        for(int i=1;i<strs.size();i++){
            int count =0;
            int n =min(strs[i].size(),ref.size());
            for(int j=0;j<n;j++){
                if(ref[j]==strs[i][j]) count++;
                else break;
            }
            minLen = min(minLen,count);
        }
        if(minLen==0) return "";
        return ref.substr(0,minLen);
    }
};