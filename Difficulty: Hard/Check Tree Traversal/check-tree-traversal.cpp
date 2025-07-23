//Back-end complete function Template for C++

class Node
{
public:
  int data;
  Node *left;  // pointing left child
  Node *right; // pointing right child
  //?Binary tree has atmost 2 childs(means max no. of child is 2 for a parent node) left and right only

  Node(int x)
  {
    data = x;
    left = nullptr;
    right = nullptr;
  }
};
class Solution{
    //logic we create a tree using preorder and inorder and inorder and post order/
    //if tree built same than they are of same tree
    //suppose if all traversal are of three differebt tree than tree will not constructed
    ////so if find func returns -1 menas target not present in inorder arr it menas traversal are of different tree so simply make bool flag false
    
    public:
    
     int find(int* inorder,int start, int end,int target){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    
     Node*tree_from_pre_in(int*inorder,int*preorder,int inStart,int inEnd,int ind,bool& flag_pre_in){
        
        //base case
        if(inStart>inEnd) return nullptr;
        
        Node*root=new Node(preorder[ind]);//create node 
        int pos=find(inorder,inStart,inEnd,preorder[ind]);//gives position of preorder[ind] in inorder array
        if(pos==-1|| flag_pre_in==0){
            flag_pre_in=0;//means traversal is not of smae tree
            return nullptr;
        }
        //for left 
        int inEnd_for_left=pos-1;
        //?inStart remain same for left part
        int ind_for_left=ind+1;
        root->left=tree_from_pre_in(inorder,preorder,inStart,inEnd_for_left,ind_for_left,flag_pre_in);
        
        //for right
        int inStart_for_right=pos+1;
        //?inEnd reamin same for right part
        int ind_for_right=ind+(pos-inStart)+1;
        //it menas (pos-inStart) ele from index ind in preorder are in left part
        //so for right part the ele will be ind+(pos-inStart)+1
        root->right=tree_from_pre_in(inorder,preorder,inStart_for_right,inEnd,ind_for_right,flag_pre_in);
        
        return root;
        
    }
    
     Node*tree_from_post_in(int*inorder,int*postorder,int inStart,int inEnd,int ind,bool& flag_post_in){
        //same base case as when preorder was given
        if(inStart>inEnd) return nullptr;
        
        Node*root=new Node(postorder[ind]);//create node
        int pos=find(inorder,inStart,inEnd,postorder[ind]);//will find in O(1) time
         if(pos==-1|| flag_post_in==0){
            flag_post_in=0;//means traversal is not of smae tree
            return nullptr;
        }
        
        //?we call for right first than left as postorder(LRN) and we are moving in reverse so (N->R->L)
        //for right
        int inStart_for_right=pos+1;
        //inEnd remain same
        int ind_for_right=ind-1;//as we move reverse so next index is ind-1 .In preorder we wer doinf ind+1 for left part
        root->right=tree_from_post_in(inorder,postorder,inStart_for_right,inEnd,ind_for_right,flag_post_in);
        
        //for left
        int inEnd_for_left=pos-1;
        //inStart remain same
        int ind_for_left=ind-(inEnd-pos)-1;//when preorder ws given we were doing ind=ind+(pos-inStart)+1 for right part
        //here as we are moving reverse we did ind_for_left=ind-(inEnd-pos)-1 for left part
          //it menas (inEnd-pos) ele from index ind in postorder are in right part
        //so for left part the ele will be ind-(inEnd-pos)-1;
        root->left=tree_from_post_in(inorder,postorder,inStart,inEnd_for_left,ind_for_left,flag_post_in);
        
        return root;
    }
    
    void preorder_t(Node*root,vector<int>&ans){
        if(root==nullptr) return ;
         ans.push_back(root->data);
        preorder_t(root->left,ans);
       
        preorder_t(root->right,ans);
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	int inStart=0;
    	int inEnd=N-1;
    	int ind1=0;
    	int ind2=N-1;
    	bool flag_pre_in=1;
    	bool flag_post_in=1;
    // 	Node*root1=tree_from_pre_in(inorder,preorder,inStart,inEnd,ind1,flag_pre_in);
    	Node*root2=tree_from_post_in(inorder,postorder,inStart,inEnd,ind2,flag_post_in);
    	
    	if(flag_pre_in==0 || flag_post_in==0) return 0;
    	
    	
    	vector<int>ans2;
    	preorder_t(root2,ans2);
    	if(N!=ans2.size()) return false;
    	else{
    	    for(int i=0;i<ans2.size();i++){
    	        if(preorder[i]!=ans2[i]) return false;
    	    }
    	}
    	return true;
    	
    } 

};

