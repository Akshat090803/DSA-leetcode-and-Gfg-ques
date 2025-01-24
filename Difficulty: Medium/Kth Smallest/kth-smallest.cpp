//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        //! Way-1 Time -O(nLogn) for all best average worst
        //?sort arr using merge or Quick Sort Heap sort etc
        //than return arr[k]
        
        //!way-2 Using MinHeap   (optimised)
        //?if we create Heap using stepdown then for heap -> O(n)
        //?we have to rmeove k ele form min heap to get kth smallest
        //? so Time-> O(n)+O(klogn) ~ O(kLogn)
        //?Time-O(klogn) 
        //in best and average case it will be good
        //?but when k=n it will become O(nlogn) (in Worst case)
        
        //!Way-3  (Use maxHeap) (more optimised)
        //?take first k ele and make a maxHeap of them
        //?time - O(k)(if we use StepDown) and Time O(klogk)(if we use priority queue)
        //Now first k ele in MAxHeap represnt first 4 small no. where top is max of threm means Kth smallest as all them will be less than in maxHeap 
        //?now iterate form i=k to i<arr.size()
        //in loop comapre arr[i] with top of MaxHeap
        //if arr[i] is smaller than top of MaxHeap menas arr[i] is the part of first k small as it is smaller than one of the ele in maxHEap
        //so pop top and push arr[i]
        //after loop complete top of maxHeap is our kth smallest
        
        //time for maxheap -> O(K) (with stepdown appr) and O(kLogk) (priority queue)
        //?in loop , we are doing pop and push (Logk+logk) and for (n-k) times
        //so for loop time-> O( (n-k)*logk ) ~ O(nLogk) - O(kLogk)
        //so combined complexity is
        //?a) when use Stepdown appr for MAxHEap creation
        // time -> O(k) + O(nLogk) - O(kLogk)
        // time -> O(nLogK)  (as form above 3 k,nlogKm kLogk nlogK is greatest)
        
        //?b) when use priority queue for maxHEap
        //Time -> O(kLogk) + O(nLogk) - O(kLogk)
        //Time->O(NlogK) (as +klogk cancels -klogk)
        
        //So time is same if we create maxHEap with priority q or stepdown approach
        //so for less code and  easiness we use priority queue
        
        //!now 
        //For way-2 time- > O(kLogN)
        //for way-3 Time-> O( nLogK)
        
        //worst case will be sma e for both i.em nlogn
        //but in best and average case way-3 will perform slightly better than way-2
        //that why way-3 is more optimised tha way-2
        
        priority_queue<int> pq; //MaxHeap
        for(int i=0;i<k;i++) pq.push(arr[i]); //push first k ele in maxHeap
        
        for(int i=k;i<arr.size();i++){
            if(arr[i]<pq.top()){
                pq.pop(); //logk
                pq.push(arr[i]); //logk
            }
        }
        
        return pq.top();
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends