/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* makeBST(vector<int>& preorder, int lower, int upper, int& ind) {

        //base cases
        if(ind>=preorder.size()) return nullptr;
      //when ele not in range of lower < ele < upper 
        if( lower > preorder[ind] || upper < preorder[ind]) return nullptr;

        // N
        TreeNode* root = new TreeNode(preorder[ind]);
        ind++;
        // left
        root->left = makeBST(preorder, lower, root->val , ind);
        // to add on left side, the ele mus be in range lower<ele<root->data
        // for left lower will be smae but upper will be root->data

        // Right
        root->right = makeBST(preorder,root->val,upper, ind);
        // to add on right side, the ele must be in range     root->data < ele <  upper
        // for right upper will be same but lower will be root->data

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        int upper=INT_MAX;
        int lower=INT_MIN;
        TreeNode*root=makeBST(preorder,lower,upper,ind);
        return root;
    }
};