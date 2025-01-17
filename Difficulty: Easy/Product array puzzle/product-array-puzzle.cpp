//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int>res;
        int total=1;
        for(int x:arr) total*=x;
        
        if(total==0){
            int zero=0;
            for(int x:arr){
                if(x==0) zero++;
            }
            //when only 1 zero is there
            if(zero==1){
                  total=1;
            for(int i=0;i<arr.size();i++){
                if(arr[i]!=0) total*=arr[i];
            }
            
             for(int i=0;i<arr.size();i++){
                if(arr[i]==0) res.push_back(total);
                else res.push_back(0);
             }
            }
            //when more than one 0 than res arr all ele will be 0
            else{
                
                for (int x:arr)res.push_back(0);
            }
          
        }
       else{
            for(int x:arr){
            res.push_back(total/x);
        }
       }
        return res;
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends