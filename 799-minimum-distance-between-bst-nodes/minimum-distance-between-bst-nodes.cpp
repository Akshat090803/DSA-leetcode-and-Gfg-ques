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
class Solution {
public:
//!way -2 here also we use inorder traversal but instead of storing ele in arr than traverse the arr later we comapre value in inorder traverssal intself

void Inorder_2(TreeNode*root, int & prev , int & min_e){
    if(!root) return;
//L
    Inorder_2(root->left,prev,min_e);
    //N
    if( prev != INT_MIN) {//to prevent int overflow
      int diff= abs(prev-root->val);
       min_e=min(min_e,diff);
    }

    prev=root->val; //now root will be prev
    //R
    Inorder_2(root->right,prev,min_e);
}
//!way1 where we store traversal in arr than later traverse arr for min
     void Inorder(TreeNode*root,vector<int> & ans){
        if (!root) return ;
         Inorder(root->left,ans);
         ans.push_back(root->val);
         Inorder(root->right,ans);
    }

    int minDiffInBST(TreeNode* root) {
        //way-1
        // vector<int>ans;
        // Inorder(root,ans);
        // int min_e=INT_MAX;
        
        // for(int i=1;i<ans.size();i++){
        //     int diff=abs(ans[i]-ans[i-1]);
        //     min_e=min(min_e,diff);
        // }
        // return min_e;
//? way-2
        int prev=INT_MIN;
        int min_e=INT_MAX;
        Inorder_2(root,prev,min_e);
        return min_e;
    }
};