class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>present(256,false);
        int maxLen=0;
        int currLen=0;
        int i =0;
        int j=0;

        while(j<s.size()){
            if(!present[s[j]]){
                present[s[j]]=true;
                j++;
                currLen++;
                maxLen=max(maxLen,currLen);
            }

            while(present[s[j]]){
                present[s[i]]=false;
                currLen--;
                i++;
            }
        }

        return maxLen;
        
    }
};