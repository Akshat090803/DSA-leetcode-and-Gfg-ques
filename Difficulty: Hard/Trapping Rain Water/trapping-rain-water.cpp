//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int max_e=INT_MIN;
        int max_ind=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max_e){
                max_ind=i;
                max_e=arr[i];
            }
        }
        
        
        int water=0;
        max_e=arr[0];
        
        for(int i=0;i<max_ind;i++){
            
            if(arr[i]>max_e){
                max_e=arr[i];
            }
            else{
                water+=abs(max_e-arr[i]);
            }
        }
        
        max_e=arr[arr.size()-1];
        for(int i=arr.size()-1;i>max_ind;i--){
            if(arr[i]>max_e){
                max_e=arr[i];
            }
            else{
                water+=abs(max_e-arr[i]);
            }
        }
        
        return water;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends