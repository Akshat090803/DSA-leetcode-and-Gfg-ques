class Solution {
  public:
    
    void longestLength(int ind1, int ind2 , int currLen,int& maxLen,string& s1, string& s2){
        if(ind1 < 0 || ind2 < 0) return ;
        
        if(s1[ind1]==s2[ind2]){
            currLen++;
            maxLen = max(maxLen,currLen);
            longestLength(ind1 -1 , ind2 -1 , currLen , maxLen,s1,s2);
           
            return ;
        }
        
      
        //when missmatch than currLen of substring will become 0 as we want continuous char
        currLen=0;
        
        //shift s1 left
        longestLength(ind1 -1 , ind2  , currLen , maxLen,s1,s2 );
        
        //shift s2 left
        longestLength(ind1  , ind2 -1 , currLen , maxLen,s1,s2 );
        
       
        
        return ;
        
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        
        //!Recursive
        // int maxLen=0;
        // int ind1 = s1.size() - 1  ;
        // int ind2 = s2.size() - 1 ;
        
       
        
        // longestLength(ind1 , ind2 , 0 ,maxLen , s1,s2,);
        
        //! With Top Down Dp , it will become complex
        
        //!For clean and simple code use bottom up
        //create dp array of 1 extra size and use 1 absed inddexing to avpid writing base case
        int n1 = s1.size()   ;
        int n2 = s2.size() ;
         vector<vector<int>>dp(n1 + 1,vector<int>(n2 + 1 ,0));
         
         int maxLen=0;
         
         for(int i=1;i<=n1;i++){
             for(int j=1;j<=n2;j++){
                 
                 if(s1[i-1] == s2[j-1]){
                     dp[i][j] = 1 + dp[i-1][j-1]; // +1 for curr letter and it gets added to comon substr kength of prev at prev char of both str
                     maxLen=max(maxLen , dp[i][j]);
                 }
                 else{
                     dp[i][j]=0; //if mismatch than length of common substr will be 0
                 }
             }
         }
        return maxLen;
    }
};