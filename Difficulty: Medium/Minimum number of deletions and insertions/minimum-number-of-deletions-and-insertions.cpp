class Solution {

  public:
    
int longestLength(int ind1, int ind2, string &s1, string &s2,vector<vector<int>>&dp){
        
        if(ind1 < 0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2]) {
            return dp[ind1][ind2]= 1 + longestLength(ind1-1,ind2-1,s1,s2,dp);
        }
        
        int s1Shift = longestLength(ind1-1,ind2,s1,s2,dp);
        
        int s2Shift = longestLength(ind1,ind2-1,s1,s2,dp);
        
        return dp[ind1][ind2] = max(s1Shift , s2Shift);
    }
    
    int minOperations(string &s1, string &s2) {
        
        //!Approach
        //long common subseq will tell how many characters are common in correct order between s1 and s2
        //longest common subseq length will be less than eqaul to length of s1 or s2
        //length of s1 - longestCommSubseq will tell how many char to be deleted from s1
        //length of s2 - longestCommSubseq will give how many char to inserted to make equal to s2
        
        // ans = deletion + insertion
         
         int ind1 = s1.size();
         int ind2 = s2.size();
         
         vector<vector<int>>dp(ind1,vector<int>(ind2,-1));
         
         int longSubseq = longestLength(ind1 - 1,ind2 - 1, s1,s2,dp);
         
         
         int deletion = ind1 - longSubseq;
         int insertion = ind2 - longSubseq;
         
         return deletion + insertion;
          
    }
};