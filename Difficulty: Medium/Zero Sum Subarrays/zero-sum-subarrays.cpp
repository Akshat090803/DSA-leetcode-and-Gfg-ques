//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // we use unordered multimap
        unordered_map<int,int> mp; //<sum,count> //inkey we will take sum and in value we will take how many time that sum occur in past
        //let prefix sum = { 2 5 8  6 8 6 8}
        // index             0 1 2  3 4 5 6
        //for prefix sum at 6th index same sum is at index 4 which menas from index 4 to index 6 net increase in sum is 0 me
        //and at index 2 also their is same sum , means form index 2 to ind 8 also subarr sum is 0
        //thats why keep track of count how many time sum occuur in past
        
        int sum=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==0) count++;
            
            if(mp.find(sum)!=mp.end()){
                count+=mp[sum];
                mp[sum]++; //increase the count for that sum
            }
            else{
                mp[sum]=1; 
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends