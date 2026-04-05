class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(256,0);
           for(char c:s) freq[c]++;

           for(int i=0;i<s.size();i++){
            if(freq[s[i]]==1) return i;
           }

           return -1;
    } 
};