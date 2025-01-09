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
     void Inorder(TreeNode*root,vector<int> & ans){
        if (!root) return ;
         Inorder(root->left,ans);
         ans.push_back(root->val);
         Inorder(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>ans;
        Inorder(root,ans);
        int min_e=INT_MAX;
        int prev=0;
        int next=1;
       while(next<ans.size()){
            int diff=abs(ans[next]-ans[prev]);

            if(diff>min_e){
                prev++; //as ans arr in ascending order, move prev to next to reduce diff
            }
            else{
                next++;
                min_e=diff;
            }
            if(prev==next) next++;
        }
        return min_e;
    }
};