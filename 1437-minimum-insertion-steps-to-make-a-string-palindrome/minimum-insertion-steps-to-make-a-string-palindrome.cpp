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

    int minInsertions(string str) {
          string s2 = str;
        reverse(s2.begin() , s2.end());
        
        int n = s2.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int longSubseq = longestLength(n-1,n-1 , str,s2,dp);
        
        return n-longSubseq;
    }
};