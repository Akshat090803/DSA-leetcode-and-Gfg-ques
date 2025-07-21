/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
         
         queue<Node*>q1;
         queue<Node*>q2;
         
         
         q1.push(r1);
         q2.push(r2);
         
         while(!q1.empty() && !q2.empty()){
             int n1=q1.size();
             int n2=q2.size();
             if(n1!=n2) return false;
             
             while(n1--){ //this loop run hwen n1==n2 so n1-- or n2-- same
                Node*temp1=q1.front();
                Node*temp2=q2.front();
                q1.pop();
                q2.pop();
                
                if(temp1->data!=temp2->data) return false;
                
                if(temp1->left) q1.push(temp1->left); 
                if(temp2->left) q2.push(temp2->left); 
                if(temp1->right) q1.push(temp1->right); 
                if(temp2->right) q2.push(temp2->right); 
                 
             }
         }
         
         return true;
         
    }
};