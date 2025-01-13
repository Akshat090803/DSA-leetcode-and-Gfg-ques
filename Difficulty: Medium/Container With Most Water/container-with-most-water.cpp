//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // Time-O(n^2)
        // int max_w=0;
        // for(int i=0;i<arr.size()-1;i++){
        //     for(int j=1;j<arr.size();j++){
        //         int area=(j-i)* min(arr[j],arr[i]);
        //         max_w=max(area,max_w);
        //     }
        // }
        // return max_w;
        
        //Time O(n)
        
        int max_w=0;
        int first=0;
        int last=arr.size()-1;
        // int second=1;
       while(first<last){
           int area=(last-first)*min(arr[first],arr[last]);
           max_w=max(max_w,area);
           
           if(arr[first]<arr[last])first++;
           else last--;
       }
       return max_w;
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