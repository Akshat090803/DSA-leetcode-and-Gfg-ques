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
    int findBottomLeftValue(TreeNode* root) {
     
        queue<TreeNode*>q;

        if(root) q.push(root);

        int bottomLeft;
        while(!q.empty()){
                int n=q.size();
                bottomLeft=q.front()->val; //in each itertaion it will get first ele of each level i.e, left most;
                //and at last iteration it will that left ele of bottom most level hence we get bottomLeft
              while(n--){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
              }

        }
        return bottomLeft;
    }
};