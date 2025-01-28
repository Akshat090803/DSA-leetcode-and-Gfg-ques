//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //!way-1 mergeSort time O(k^2LogK^2)
        //create a 1D arr and push all ele in it of 2d array
        //now size of 1d aarr will k^2 as k^2 ele is in it
        //apply merge sort in it so Time k^logk^2 ~ k^2logk
        //is we take 1d arr as auxilary spae still we need k^2 space in mergin process
        //so space is O(k^2) and time is O(k^2LogK^2) ~ O(k^2logk)
        
        //!way-2 Heap sort time O(k^2LogK^2) ~ O(k^2logk)
        //similar to way-1 just sort using heap sort
        //but space will be O(1)
        
        //!way-3 use minHeap
        // time O(k^2LogK^2) ~ O(k^2logk)
        //space O(k^2)
        //create a min heap push all ele of 2d arr in it
        //pop one by one from minHeap 
        
        //!way-4 similar to kth smallest ele in 2d array
        //time  O(k^2logk)  
        //space O(k) as at most k ele will be in minHeap
        //at most k ele in heap so time for their insertion and dleetion in each iteration is logk
        //we have to do it for k^2 ele so time is O k^2logk
        //only difference is that we have to add perform action till heap is not empty unlike in kth element in 2d matrix where we to perform while(k--) as we want kth smallest ele
        
        //?in way-1 ,way-2 ,way-3 all have time  O(k^2LogK^2) which approximately taken as O(k^2logk)
        //?but in way-4 already time is k^2logk and not k^2logK^2 so way-4 will perform slightlt better than way-1 to way-3
        
        
        //!we will store pair to store in heap
        //we can use class also and make a customised min heap 
        //but for pair it automatically handles comparision , we will use pair
        
        vector<pair<int,pair<int,int>>> temp;
        //push first col ele
        for(int i=0;i<k;i++){
            temp.push_back({arr[i][0],{i,0}});
        }
        
        //make minHeap priority queue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
        
        vector<int>ans;
        while(!pq.empty()){
            pair<int,pair<int,int>>Ele=pq.top();
            pq.pop();
             ans.push_back(Ele.first);
            int i=Ele.second.first;
            int j=Ele.second.second;
            if(j+1<k){///when next ele exist
                pq.push({arr[i][j+1],{i,j+1}});
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends