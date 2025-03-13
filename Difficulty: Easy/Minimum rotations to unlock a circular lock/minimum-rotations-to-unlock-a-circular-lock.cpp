//{ Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    int rotationCount(long long R, long long D)
    {
        
        //for each digit we will take minimum of distance in rotating clockwise and anticlockwise
        int count=0;
        
        while(R){
            int r=R%10;
            int d=D%10; //for getting one one digit
            R/=10;
            D/=10;
            
            int clockWise=abs(r-d);
            int antiClockWise=10-clockWise;
            
            count += min(clockWise,antiClockWise);
            
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long R, D;
        cin>>R>>D;
        
        Solution ob;
        cout<<ob.rotationCount(R, D)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends