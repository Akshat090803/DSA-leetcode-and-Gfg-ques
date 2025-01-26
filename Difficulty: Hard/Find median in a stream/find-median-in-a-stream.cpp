//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //!Way-1 with using vector instead of heap even though func na,e indicates to use Heap
    //Time of getMedian func() is O(1)
    //Time for insertHeap() func is nlogn as in each insertion we are doing sorting
    //?so for n insertion time will be n*nLogn = n^2logn 
    //?as the required complexity is nlogn and our complexity is n^2logn there will be time limit exceeded
    // //Function to insert heap.
    // vector<int>v;
    // void insertHeap(int &x)
    // {
    //  v.push_back(x);
    //  sort(v.begin(),v.end());
    //  getMedian();
    // }
    
    //   //Function to return Median.
    // double getMedian()
    // {   int n=v.size();
    // double med;
    //     if(n%2==0){
    //       med=(v[n/2] + v[(n/2)-1])/2;
    //     }
    //     else{
    //         med=v[n/2];
    //     }
    //     return med;
    // }
    
    
      
//       //!way-2 using minHeap . Still time is O( n^2logn )
// priority_queue<int,vector<int>,greater<int>>pq;
// //Function to insert heap.
//     void insertHeap(int &x)
//     {
//     pq.push(x);
//     }
//     //Function to return Median.
//      double getMedian()
//     {   
//         int n=pq.size();
//         vector<int>v;
//         int data;
//         if(pq.size()==1) return pq.top();
    
        
//             int k=n/2;
//             while(k--){
//                 data=pq.top();
//                 v.push_back(data);
//                 pq.pop();
//             }
//             int top=pq.top();
//             for(auto x:v) insertHeap(x);
            
//             if(n%2==0) return (data+top)/2;
//             else return top;
      
       
//     }
    
    //we use two heaps maxHeap(left side heap) and min heap (right side heap)
    // priority_queue<int>leftMaxHeap; //maxHeap
    // priority_qu eue<int,vector<int>,greater<int> > rightMinHeap; //minHeap
    
    // void insertHeap(int &x)
    // {
    //   // If maxHeap is empty or the new element is less than or equal to the top of maxHeap,
    //     // insert into maxHeap.
    //     if(leftMaxHeap.empty() || x <= leftMaxHeap.top()) {
    //         leftMaxHeap.push(x);
    //     }
            
    //     else {
    //         rightMinHeap.push(x);
    //     }
            
    //     // Balance the heaps after insertion.
    //     balanceHeaps();
      
    // }
    // //Function to balance heaps.
    // void balanceHeaps()
    // {   
    //     //right minHeap size should not be greater than leftMaxHeap
    //     //if RightMinHeap size is greater than left MAx heap size transfer ele from right to left
    //     if(rightMinHeap.size() > leftMaxHeap.size()){
    //         leftMaxHeap.push(rightMinHeap.top());
    //         rightMinHeap.pop();
    //     }
    //     else{
            
    //         //?if leftMaxHeap is just one size bigger than don't transfer ele as the extra one will be the median in odd size case
    //         //but if leftMaxHeap is bigger than one size i.e, difference b/w left and right is greater than 1 transfer ele from left to right
    //         if(leftMaxHeap.size()-rightMinHeap.size() > 1){
    //             rightMinHeap.push(leftMaxHeap.top());
    //             leftMaxHeap.pop();
    //         }
    //     }
    // }
    
    // //Function to return Median.
    // double getMedian()
    // {   
    //   //case of odd size 
    //   if(leftMaxHeap.size() > rightMinHeap.size()) return leftMaxHeap.top();
    //   else{ //for even size;
          
    //       double ans=leftMaxHeap.top() + rightMinHeap.top();
    //       ans=ans/2;
    //       return ans;
    //   }
    // }
     // Declaring maxHeap as a max-priority queue
    priority_queue<int> maxHeap;
    
    // Declaring minHeap as a min-priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Function to insert elements into the appropriate heap.
    void insertHeap(int &x)
    {
        // If maxHeap is empty or the new element is less than or equal to the top of maxHeap,
        // insert into maxHeap.
        if(maxHeap.empty() || x <= maxHeap.top()) 
            maxHeap.push(x);
        else 
            minHeap.push(x);
        
        // Balance the heaps after insertion.
        balanceHeaps();
    }
    
    // Function to balance the heaps to ensure their sizes differ by at most one.
    void balanceHeaps()
    {
        // If minHeap has more than one extra element, move the top element to maxHeap.
        if(minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // If maxHeap has more than one extra element, move the top element to minHeap.
        else if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    // Function to return the median of the elements inserted so far.
    double getMedian()
    {
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();
        
        // If both heaps have the same number of elements, the median is the average of the two tops.
        if(minHeapSize == maxHeapSize)
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        // If minHeap has more elements, the median is the top of minHeap.
        else if(minHeapSize > maxHeapSize)
        {
            return minHeap.top();
        }
        // If maxHeap has more elements, the median is the top of maxHeap.
        else
        {
            return maxHeap.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends