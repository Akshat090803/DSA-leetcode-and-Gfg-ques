//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        //!way-1 Time-O(n^2) space- O(1)
    //     int len=0;
    //     for(int i=1;i<arr.size();i++){//this loop for how many subarray for size n
    //         int zero=0,one=0;
    //         for(int j=i-1;j<arr.size();j++){
    //             if(arr[j]==0) zero++;
    //             else one++;
                
    //             if(zero==one){
    //                 len=max(len,zero+one);
    //             }
    //         }
    // }
    // return len;
    
    //!Way-2 Time-O(n)  Space O(n)
    //To solve this problem, we want to find the maximum length subarray where the number of 0s and 1s are the same. This can be rephrased as finding a subarray where the cumulative sum of the elements (after transforming 0 to -1) equals zero.
    //Use a hash map to track prefix sums:
    //Calculate the cumulative sum while iterating through the array.from the start to the current index is balanced.
    //Store the first occurrence of each cumulative sum in a hash map. If the same sum reoccurs, it implies that the subarray between these indices is balanced.
    //If sum exists in the map, calculate the length of the subarray between the current index and the earlier index where the sum was found.
    
    for(int i=0;i<arr.size();i++) if(arr[i]==0) arr[i]=-1;
    
    int sum=0;
    int max_len=0;
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++ ){
        sum+=arr[i];
        
        if(sum==0){
            max_len=max(max_len,i+1);
        }
        
        if(mp.count(sum)){//when sum exist in map
            int subarr_len=i-mp[sum];
            max_len=max(max_len,subarr_len );
        }
        else{//when sum not exist in map
           mp.insert(make_pair(sum,i)); 
        }
        
    }
        return max_len;
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends