class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        

        //fillinf the dp array bottom Up
             int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    // creating shortest common subsequence string
    //backtrack dp array
    string sub;

    int i = n1;
    int j = n2;

    while(i > 0 && j > 0){

        if(str1[i-1] == str2[j-1]){
            sub+=str1[i-1];  
            i--;
            j--;
            //move diagonaly up
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            sub+=str1[i-1];
            i--;
        }else{
            sub+=str2[j-1]; // for i,j we following 1 based index
            // but in string the correct index when we are at i will i-1 and respectively j-1 when at j;  that's why in sub+=str2[j-1] j-1 means char at jth col of dp table
            j--;
        }
    }
    
    while(i>0) sub+=str1[i-1] , i--;

    while(j>0) sub+=str2[j-1] , j--;
    
    reverse(sub.begin(),sub.end());
    return sub;
    }
};