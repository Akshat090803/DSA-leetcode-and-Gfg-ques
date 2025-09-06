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
    int longestCommonSubsequence(string text1, string text2) {
            // int ind1 = text1.size();
            // int ind2 = text2.size() ;

            // vector<vector<int>>dp(ind1 , vector<int>(ind2,-1));
            // return  longestLength(ind1 - 1,ind2 - 1,text1,text2, dp);

            //!bottom up
        //       int n1 = text1.size();
        //     int n2 = text2.size() ;

        //      vector<vector<int>>dp(n1 , vector<int>(n2,0));

        //      //base case //match first char of text 1 with all char of text2
        //      for(int i=0;i< n2 ; i++){
        //         if(text1[0]==text2[i]) dp[0][i]=1;

        //         if(i>0)
        //         dp[0][i]=max(dp[0][i] , dp[0][i-1]);
        //      }
             
        //      //base case for col 0 of each row
        //      for(int i=1;i<n1;i++){
        //          if(text1[i]==text2[0]) dp[i][0]=1;

        //          dp[i][0]=max(dp[i][0] , dp[i-1][0]);
        //      }
             
        //      for(int i=1;i<n1;i++){
        //         for(int j=1;j<n2;j++){

        //             if(text1[i]==text2[j]){
        //                 dp[i][j]=1 + dp[i-1][j-1];
        //             }
        //             else {
        //                 dp[i][j] = max (dp[i-1][j] , dp[i][j-1]);
        //             }
        //         }
        //      }

        //  return dp[n1-1][n2-1];

         //!optimizes bottom up (Note this is not space optimzation)
//?          We can shorten the bottom-up DP version of LCS quite a bit if we remove the manual base case handling.
// ?The trick is to make your dp table of size (n1+1) × (n2+1) and shift indices by 1.
// ?That way, we don’t need to write separate loops for row 0 and col 0.
       
        int n1 = text1.size(), n2 = text2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n1][n2];
    
    }
};