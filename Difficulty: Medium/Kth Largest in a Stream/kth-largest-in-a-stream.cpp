//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        //Like kth greatest ele but with little variation
        //we have to return a vector that contains kth largest ele
        //for k-2 indexes value will be -1 as we have not reached kth greatest ele yet
        //from k-1 idnexes we will follow same concept of kth largest ele
        //see example to understand for -1 logic
        //let k=4 than upto index 2 value will be -1 as at index 2 we have reached till 3rd largest ele only
        
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>kth_largest_arr(n,-1);
        
        for(int i=0;i<k;i++) pq.push(arr[i]);
        
        kth_largest_arr[k-1]=pq.top();
        
        for(int i=k;i<n;i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
            kth_largest_arr[i]=pq.top();
        }
            
            return kth_largest_arr;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends