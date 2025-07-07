class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string longest=strs[0];

         for(int i=0;i<strs.size()-1;i++){
            int minind=min(strs[i].size(),strs[i+1].size());
            int j=0;
            string temp="";
            while(j<minind){
                if(strs[i][j]==strs[i+1][j]){
                    temp+=strs[i][j];
                }
                else{
                    break;
                }
               //to avoid unneccsary comparision when , current common exceeds longest common till ith 
                if(temp.size()>longest.size()){
                    break;
                }
                j++;
            }

            if(temp.size()<longest.size()){
                longest=temp;
            }
         }
         return longest;
    }
};