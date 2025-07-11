class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // suppose s1="aba" and s2="akshbaat"
        //all permutation of s1 will have same freq of its char i.e, a=2 b=1;
        //so run a fixed size sliding window , in each frame count freq of char in that frame , and compare with the freq of s1 chars ,
        vector<int>s1Freq(26,0);
        for(char x:s1) s1Freq[x-'a']++;
        int n=s2.size();
        //created fixed sized window
        int start=0, end=s1.size()-1;

        while(end<n){
           vector<int>windowFreq(26,0);
           for(int i=start;i<=end;i++){
            windowFreq[s2[i]-'a']++;
           }

           bool chk=true;
           //this loop can be run from int i=0 to i<s1.size() and do
           // s1[i]-'a' instead of s2[i]-'a'
            for(int i=start;i<=end;i++){
             if(windowFreq[s2[i]-'a'] != s1Freq[s2[i]-'a']){
                chk=false;
                break;
             }
           }
           if(chk) return true;

           start++;
           end++;
        }

        return false;
    }
};