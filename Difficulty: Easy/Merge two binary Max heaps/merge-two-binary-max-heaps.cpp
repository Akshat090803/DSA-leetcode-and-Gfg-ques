//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void Heapify(vector<int>&ans,int parent ,int n){
      while(parent < n/2){
            int leftChild=2*parent+1;
        int rightChild=2*parent+2;
        
        int largest=parent;
        
        if(leftChild<n && ans[leftChild] > ans[largest]){
            largest=leftChild;
        }
        
        if(rightChild<n && ans[rightChild] > ans[largest]){
            largest=rightChild;
        }
        
        if(largest==parent) return;
        else{
            swap(ans[parent] , ans[largest]);
            parent=largest;
        }
      }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        //!Way-1 Time O( (n+m)*Log(n+m) ) ~ O(nlogn)
        //create a priority queue and push ele of both vector in it
        //then pop ele one by one from priority queue and push in ans vector
        //return ans
        //!as in ques required time is O(nlogn) so we can solve this ques with above approch way-1
        
        
        //!way-2 Time O(n+m) (Optimised)
        //create a ans vector and push ele of both vector in ans vector
        //Now create a max heap of ans vector using stepdown approch (using heapify func)
        //by stepdown approach we will get max heap in O(n+m) time 
        
        vector<int>ans;
        
        //push vector 1 ele in ans
        for(auto x:a) ans.push_back(x);
        
        //push vector 2 ele in ans
        for(auto x:b) ans.push_back(x);
        
        //construct maxHEap of ans vector
        //call heapify func fromm n/2-1 th index to 0th index
        int size=ans.size();
        for(int i=size/2-1;i>=0;i--){
            Heapify(ans,i,size);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends