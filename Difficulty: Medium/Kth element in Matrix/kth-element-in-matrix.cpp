//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    
cout << "~" << "\n";
}
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //!way-1 Time O(N^2)+ O(N^2Logn)
  //create a 1d vector and store all the ele of 2d matrix in 1d vec O(n^2)
  //create a minHeap of 1d vec having N^2 ele than Time- O(N^2logN^2) ~ O(N^2logn)
  
  //!way-2 optimised O(klogn)
  //create a min Heap of col 0 ele. O(n) using priority quue v.begin(),v.end()
  //in heap store data , and its col and row index.For that we use pair
  //run while loop while(k--)
  //each time pop ele fromfin heap and push next ele of its row thst i,j+1 th ele
  //at most we have to do k pop and k push so logn+logn=2logn
  //and for k time it will be klogn
  //overall complexity -> O(n) + O(klogn) ~ O(klogn)
  
  //?as we have to store value,rowindex col index we use pair
  
  vector< pair<int,pair<int,int>> > vec;
  for(int i=0;i<n;i++){
      vec.push_back({mat[i][0] , {i,0} }); //store all ele of col 0
  }
  
  //create a minHeap that will store pair Time O(n) as we give vector iterator also
  priority_queue< pair<int,pair<int,int>> , vector< pair<int,pair<int,int>> > , greater< pair<int,pair<int,int>> > >pq (vec.begin(),vec.end());
  int data,i,j;
  while(k--){
      pair<int,pair<int,int>> Element=pq.top();
      pq.pop();
       data=Element.first;
       i=Element.second.first;
       j=Element.second.second;
      
      //push next ele of that row i.e mat[i][j+1]
      if(j+1 < n) pq.push({mat[i][j+1] , {i,j+1} });
      //only push if next ele is not out of bound
      
  }
  
  return data;
}
