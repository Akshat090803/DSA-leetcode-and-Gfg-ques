
class Solution {
  public:
  //?for way-1 Space-O(n)
   void Inorder(Node*root,vector<Node*>&ans){
         if(root==nullptr) return;
        //l
        Inorder(root->left,ans);
        //N
        ans.push_back(root);
        //R
        Inorder(root->right,ans);
   }
    void correctBST( struct Node* root )
    {
        //!expected time-O(n) space - O(1)
        
        //?way 1- Time-O(n) Space O(n)
        //find inorder traversal and store in arr
        //as two nodes are swapped so in their inorder traversal also at two position , there will be wrong value
        //so find that wrong value and swapp that values to correct the BST
        // vector<Node*>ans;//stores root instead of their value so that we can directly swap instead of agin traversing the root
        // Inorder(root,ans);
        // Node* first=nullptr,*second=nullptr;
        // Node* last=nullptr;
        // Node*present=nullptr;
        
        // for(int i=0;i<ans.size();i++){
        //     present=ans[i];
        //     //when problem in inorder traversal (i., wrong value)
        //     if( last && present->data<last->data){
        //         //in asc order previous node is always smaller than curr node
        //         //so if prev node is greater than curr node it means something is wrong
        //         if(first==nullptr){
        //              first=last;//first wrong node
        //         }
        //         second=present;//second wrong node
        //     }
            
        //     last=present;
        // }
        
        // //now swap
        // int num= first->data;
        // first->data=second->data;
        // second->data=num;
        
        //?-------------------------------------------->
        
        //!Way-2 Time-O(n)  Space O(1)
        //as we need space O(1) we will use Morris Traversal
        Node*first=nullptr,*second=nullptr;
        Node*last=nullptr,*present=nullptr;
        
        while(root){
            
            if(root->left){//if left exist
                //go to right most node from left that is rightmost node of root->left
                Node*curr=root->left;
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }
                
                //two case 
                //1) left part not traversed
                if(curr->right==nullptr){
                    //make curr->right point root and simply go left
                    curr->right=root;
                    root=root->left;
                }
                else{
                    //left part already traversed i.e, when curr->right=root
                    curr->right=nullptr;//break link
                    
                    //check for wrong/swapped Node
                    present=root;
                    if(last && present->data < last->data){
                        if(first==nullptr){
                            first=last;
                        }
                        second=present;
                    }
                    
                    last=present; //prsent root will be now last for next node in traversal
                    root=root->right;
                    //left part already traversed so move right
                }
            }
            else{
                //when left part not exist (else part of first if conditon)
                  //check for wrong/swapped Node
                    present=root;
                    if(last && present->data < last->data){
                        if(first==nullptr){
                            first=last;
                        }
                        second=present;
                    }
                    
                    last=present; //prsent root will be now last for next node in traversal
                    root=root->right;
                    //left part Not exist so move right
            }
        }
        
         //now swap
        int num= first->data;
        first->data=second->data;
        second->data=num;
    }
};
