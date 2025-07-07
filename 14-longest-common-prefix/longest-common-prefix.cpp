class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int count =0;
        int end=INT_MAX;
        int size=strs.size();
        if(size==1) return strs[0];

        for(int i=1;i<size;i++){
            int j=0;
            int n=min(strs[i].size() ,strs[0].size());
            count=0;
           

            while(j<n){
                     if(strs[0][j]==strs[i][j]){
                        count++;
                     }else{
                        break;
                     }
                     if(count > end){
                        break;
                     }
                        j++;
            }
            end=min(end,count);
         
        }

        string ans;
        for(int i=0;i<end;i++){
            ans+=strs[0][i];
        }
        return ans;
    }
};