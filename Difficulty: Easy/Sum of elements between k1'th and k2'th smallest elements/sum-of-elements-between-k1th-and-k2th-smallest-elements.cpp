//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long k1, long long k2)
    {
        //required time O(N. log(N))
        //!Way-1
        //so we can sort the arr(usinf merge sort or quick or heap sort) and then return sum of ele b/w k1 and k2
        
        //!way-2 
        //create min heap
        //remove  till k1th 
        //total ele b/1 k1 and k2 = k2-k1-1
        //run while total_ele-- and store sum
        //Time - O(nLogn) which is required
        //so no need to use way-3 of (kth smallest ele) method 
        
        long long sum=0;
        int ele_between=k2-k1-1;
        
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        for(int i=0;i<N;i++) pq.push(A[i]);
        
        while(k1--) pq.pop(); 
        
        while(ele_between--) {
            sum+=pq.top();
            pq.pop();
        } 
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends