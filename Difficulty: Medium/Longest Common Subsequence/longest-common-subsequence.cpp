class Solution {
  public:
  
     int longestLength(int ind1,int ind2, string &text1,string &text2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]) {
            //shift both
            return dp[ind1][ind2] = 1 + longestLength(ind1-1,ind2-1,text1,text2, dp);
        }

        //move left in text1
         int shiftText1 = longestLength(ind1-1,ind2,text1,text2, dp);
        //move left in text 2
        int shiftText2 = longestLength(ind1,ind2-1,text1,text2, dp);

        return dp[ind1][ind2] = max(shiftText1 , shiftText2);
    }
    
    int lcs(string &text1, string &text2) {
        // code here
          int ind1 = text1.size();
            int ind2 = text2.size() ;

            vector<vector<int>>dp(ind1 , vector<int>(ind2,-1));
            return  longestLength(ind1 - 1,ind2 - 1,text1,text2, dp);

    }
};
