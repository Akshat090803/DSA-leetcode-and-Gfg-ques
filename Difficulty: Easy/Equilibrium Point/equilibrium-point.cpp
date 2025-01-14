//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // As required Space is O(1) we will not create Suffix and prefix arr
        //instead we will simultaneously find prefix and suffix;
        int prefix_sum=0;
        int total_sum=0;
        
        
         //calculate total sum
        for(x:arr) total_sum+=x;
        
        //final code
        for(int i=0;i<arr.size();i++){
            prefix_sum+=arr[i];
            int suffix=total_sum;
            
            if(prefix_sum==total_sum) return i;
            
            total_sum-=arr[i];
        }
        
        return -1;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends