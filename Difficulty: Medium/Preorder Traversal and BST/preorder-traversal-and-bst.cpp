//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Node{
    public:
     int data;
     Node*left,*right;
     Node(int x) {
      data=x;
      left=right=nullptr;
     }
};


class Solution {
  public:
  
  Node* makeBST(int post[],int lower,int upper, int & ind,int N){
    
    //base condition when index go out of bound
    if(ind>=N) return nullptr; //as we are going in revrse i.e, ind=arr.size to i=0 
    
    //when ele not in range of lower < ele < upper 
    if( lower > post[ind] || upper < post[ind]) return nullptr;
    
    //in pre order(N L R) we are followinf N LR
    //in post order (L R N) we go in revrse so that to create node first 
    //!so we consider right part first before left part
    
    Node* root= new Node(post[ind]);
    ind++; //we are traversing from end
    
       // left
    root->left = makeBST(post, lower, root->data , ind,N);
    // to add on left side, the ele mus be in range lower<ele<root->data
    // for left lower will be smae but upper will be root->data

    
      // Right
     root->right = makeBST(post,root->data,upper, ind,N);
    // to add on right side, the ele must be in range     root->data < ele <  upper
    // for right upper will be same but lower will be root->data
    
  
    return root;
    
}

void preorder(Node*root,vector<int> &ans){
    if(root==nullptr) return;

  ans.push_back(root->data);
  preorder(root->left,ans);
  preorder(root->right,ans);
}
    int canRepresentBST(int arr[], int N) {
        int ind=0; //bcoz in Post order root ele is at end of arr
        int upper=INT_MAX;
        int lower=INT_MIN;
        Node*root=makeBST(arr,lower,upper,ind,N);
        vector<int>ans;
        preorder(root,ans);
        if(ans.size()!=N) return 0;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=arr[i]) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends