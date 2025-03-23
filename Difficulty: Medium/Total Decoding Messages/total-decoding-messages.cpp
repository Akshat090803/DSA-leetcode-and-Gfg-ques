//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
  //!With recursion without dp we got T.L.E
  
  int countWays(int i , int n,string & digits,vector<int>&dp){
      if(i==n)
      return 1;
      
      if(i>n)
      return 0;
      
      if(digits[i]=='0')
      return 0;
      
      if(dp[i]!=-1)
      return dp[i];
      
      int ret1=countWays(i+1,n,digits,dp);
      int ret2=0;
      
      if(i<n-1){
          int one=digits[i]-'0';
          int two=digits[i+1]-'0';
          int num=one*10+two;
          if(num<=26){
              ret2=countWays(i+2,n,digits,dp);
          }
      }
      
      return dp[i]=ret1+ret2;
  }
    int countWays(string &digits) {
        
        //!Without dp and only recursion we got T.L.E
        
        int n=digits.size();
        vector<int>dp(n,-1);
        //!dp arr will tell form index i how many ways are there for decode .Hence we not need to make call again for smae index i
        //!dp[i]  will store the number of ways to decode the substring starting at index i.
        return countWays(0,n,digits,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends