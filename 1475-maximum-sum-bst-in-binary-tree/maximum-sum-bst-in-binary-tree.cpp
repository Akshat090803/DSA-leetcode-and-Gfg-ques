/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Box{
    public:
       int sum,min,max;//here we take var sum instead of size
       bool BST;
       
       Box(int x){
           sum=x; 
           min=INT_MAX;
           max=INT_MIN;
           BST=1;
       }
};
  
class Solution {
public:
//!similar to largest BST problem (in GFG).In largest BST problem we were calculating size here we will calculate Sum

Box* largest_sum(TreeNode* root, int& max_sum){
        
        	if(root==nullptr){
    	    Box* newBox = new Box(0);//create box with sum =0 as when root is null
    	    return newBox;
    	}
    	else{
    	    
    	    Box* left=largest_sum(root->left,max_sum);
    	    Box* right=largest_sum(root->right,max_sum);
    	    
    	    //check for Valid BSt
              //for valid BST SUbtree ,
          //root must be gretaer than max value on left part 
          //root must be smaller than min value on right part as as on right the min value will also be greater than root bcoz we send ele greater than root on right
    	    if(left->BST && right->BST && root->val>left->max && root->val<right->min){
    	        int  new_sum=root->val+left->sum+right->sum;
    	        Box* newBox= new Box(new_sum);
    	        newBox->min=min(left->min,root->val);
    	        newBox->max=max(right->max,root->val);
    	        max_sum=max(max_sum,new_sum);
    	        return newBox;
    	    }
    	    
    	    else{//when not a valid BST
    	    
    	        left->BST=0; //make BST false for either left or right 
    	        return left;
    	        //we can ,make BST false for right also then we have to return right
    	        
    	    }
    	}
    }

    int maxSumBST(TreeNode* root) {
        int max_sum=0;
        largest_sum(root,max_sum);
        return max_sum;
    }
};