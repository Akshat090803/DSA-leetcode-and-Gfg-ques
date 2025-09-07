class Solution {
public:
    int longestPalindromeSubseq(string s) {
         //this is exact simialr to Longest common subsequence
        //only difference is that in LCS we were given two string text1 and tex2
        //whereas in this we have only one string s
        //We know pallindromic string is who which str = rev(str)
        //so in This second string will be revrse of first string than the length of longest subsequence btween this two str will be the longest palindrom subsequence length
        
        string s2 = s;
        reverse(s2.begin(),s2.end());
        
        int n1 = s.size();
        //n2 == n1 as both string will be of same length
        
        //create dp array 1 size extra and foolow 1 based indexing so as to avoid writing base cases
        vector<vector<int>>dp(n1+1 , vector<int>(n1+1 , 0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1 ; j<=n1 ; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n1];
    }
};