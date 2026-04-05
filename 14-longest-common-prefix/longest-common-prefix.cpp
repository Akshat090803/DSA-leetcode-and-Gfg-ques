class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     int minLen = INT_MAX;
   
    //     string ref = strs[0];
    //     for(int i=1;i<strs.size();i++){
    //         int count =0;
    //         int n =min(strs[i].size(),ref.size());
    //         for(int j=0;j<n;j++){
    //             if(ref[j]==strs[i][j]) count++;
    //             else break;
    //         }
    //         minLen = min(minLen,count);
    //     }
    //     if(minLen==0) return "";
    //     return ref.substr(0,minLen);
    // }
    string longestCommonPrefix(vector<string>& strs) {

    sort(strs.begin(),strs.end());

    string first=strs[0];
    string last=strs[strs.size()-1];

    string result="";

    for(int i=0;i<first.size();i++){

        if(first[i]==last[i])
            result+=first[i];

        else
            break;
    }

    return result;
}
};