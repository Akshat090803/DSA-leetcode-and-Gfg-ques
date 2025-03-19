//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    // int ways(int n){
    //     if(n==1) return 1; // only 1 is valid
    //     if (n==2) return 2;//1+1 or 2 are valid so total ways=2
    //     if(n==3) return 4;//1+1+1 , 2+1, 1+2, 3 so total ways=4
        
    //     int n_1= ways(n-1);
    //     int n_2=ways(n-2);
    //     int n_3=ways(n-3);
    //     return n_1+n_2+n_3;
    // }
    
     int ways_2(int n,int s){
        if(n==s)
        return 1;
        if(s>n)
        
        return 0;
        
        int n_1= ways_2(n,s+1);
        int n_2=ways_2(n,s+2);
        int n_3=ways_2(n,s+3);
        return n_1+n_2+n_3;
    }
    int countWays(int n) {

        // your code here
        // return ways(n);
        return ways_2(n,0);
    }
};


//{ Driver Code Starts.
int main() {
    // taking testcases
    int t;
    cin >> t;

    while (t--) {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends