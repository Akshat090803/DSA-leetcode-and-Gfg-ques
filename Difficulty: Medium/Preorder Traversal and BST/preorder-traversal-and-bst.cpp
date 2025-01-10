//User func template for c++
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
  
  Node* makeBST(int arr[],int lower,int upper, int & ind,int N){
    //base condition when index go out of bound
    if(ind>=N) return nullptr; //as we are going in revrse i.e, ind=arr.size to i=0 
    
    //when ele not in range of lower < ele < upper 
    if( lower > arr[ind] || upper < arr[ind]) return nullptr;
    
    //N
    Node* root= new Node(arr[ind]);
    ind++; 
    
       // left
    root->left = makeBST(arr, lower, root->data , ind,N);
      // Right
     root->right = makeBST(arr,root->data,upper, ind,N);
   
    return root;
}

void preorder(Node*root,vector<int> &ans){
    if(root==nullptr) return;
  ans.push_back(root->data);
  preorder(root->left,ans);
  preorder(root->right,ans);
}

//!way -2
 void makeBST_2(int arr[],int lower,int upper, int & ind,int N){
    //base condition when index go out of bound
    if(ind>=N) return ; //as we are going in revrse i.e, ind=arr.size to i=0 
    
    //when ele not in range of lower < ele < upper 
    if( lower > arr[ind] || upper < arr[ind]) return ;
    
    //N
   //just update index 
   int root_data=arr[ind]; //we didn't create node but store the value of the node so that we can pass it as upper when calling for left and lower when calling for right
    ind++; 
    
       // left
       makeBST(arr, lower,root_data  , ind,N);
      // Right
       makeBST(arr,root_data,upper, ind,N);
   
    
}
 
    int canRepresentBST(int arr[], int N) {
        
        //! Way-1 
        //construct the BST from Given Preorder just like we did in previous ques
        //store the preorder of BST build in an array
        //compare the size of given arr and  ans arr(arr storing preorder taversal of tree constructed)
        //If given arr is a preorder of possible BST than the size of BST preorder traversal arr and given arr will be same
        //SO if size equral return 1
        //else return  0
       //Time -O(n) as makeBST func take O(n) time ,preorder func take O(n) time 
       //SO time-> O(2n) ~ O(n)
        // int ind=0; 
        // int upper=INT_MAX;
        // int lower=INT_MIN;
        // Node*root=makeBST(arr,lower,upper,ind,N);
        // vector<int>ans;
        // preorder(root,ans);
        // if(ans.size()!=N) return 0;//!This is important 
   
        // return 1;
        
       ///! WAy- 2
       //?We use same makeBST func (with some changes) don't create any node just update ind only
       //if after returning from all calls of func if ind==N than it means given arr is possible preorder of BST
       //if ind!=N return 0 as given arr not a preorder of possible BST
       //?This is like way1 we were comparing size of given Arr and Preorder arr of build BSt
       //ind!=N means bst formed don't have all the ele of given arr
       //so if we find preoder of constructed BST its size will be less than (not equal) to given arr
       //?So we saved time for proeorder func and Save space by not creating actual BST
       
         int ind=0; 
        int upper=INT_MAX;
        int lower=INT_MIN;
        makeBST_2(arr,lower,upper,ind,N);
      
        if(ind==N) return 1;//!This is important 
        
        return 0; //when ind!=N
   
    }
};
