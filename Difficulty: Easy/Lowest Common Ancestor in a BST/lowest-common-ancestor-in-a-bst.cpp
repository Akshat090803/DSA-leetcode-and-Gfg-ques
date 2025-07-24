/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void findLCA(Node*root, int n1,int n2, Node* &lca){
        if(lca || !root) return;
        if(root->data >= n1 && root->data <= n2 || root->data >= n2 && root->data<=n1){
            lca=root;
            return;
        }
        
        if(n1>root->data && n2>root->data){
            findLCA(root->right,n1,n2,lca);
        }
        else{
             findLCA(root->left,n1,n2,lca);
        }
    }
    
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        
        Node*lca=nullptr;
        findLCA(root,n1->data,n2->data,lca);
        return lca;
    }
};