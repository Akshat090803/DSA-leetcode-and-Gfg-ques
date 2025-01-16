//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
  
   //get height func
  int getHeight(Node*root){
      if(root==nullptr) return 0;
      
      return root->height;
  }
  
  //!right Rotaion
  Node* rightRotation(Node*root){
      Node * child=root->left;
      Node*childRight=child->right;
      
      child->right=root;
      root->left=childRight;
      
      //update Height of root and child;
      //first update height of root as now it is become a child(as it is rotated it comes down and previous child that store in child var is new root so it height will update later)
      root->height=1+ max(getHeight(root->left),getHeight(root->right));
      //now update child height (which is now act as a root)
      child->height=1+ max(getHeight(child->left),getHeight(child->right));
      
      
      return child; //as now child act as a root
  }
  
  //!Left Rotaion
  Node* leftRotation(Node*root){
      Node * child=root->right;
      Node*childLeft=child->left;
      
      child->left=root;
      root->right=childLeft;//left child of child node will attch to right of root
      
      //update Height of root and child;
      //first update height of root as now it is become a child(as it is rotated it comes down and previous child that store in child var is new root so it height will update later)
      root->height=1+ max(getHeight(root->left),getHeight(root->right));
      //now update child height (which is now act as a root)
      child->height=1+ max(getHeight(child->left),getHeight(child->right));
      
      return child; //as now child act as a root
  }
  
 
    /*You are required to complete this method */
    Node* insertToAVL(Node* root, int key)
    {
        if(root==nullptr){ //node created is always at end
            root=new Node(key);
            return root;
        }
        
        if(key<root->data){//will be added at left
            root->left=insertToAVL(root->left,key);
        }
        else if(key > root->data){//will add at right
            root->right=insertToAVL(root->right,key);
        }
        else{//when key==root i.em similar value(duplicate) 
         return root;//duplicated not allowed that whu we not created node with value =key
        }
        //update height for root
        root->height=1+ max(getHeight(root->left),getHeight(root->right));
        //while returning from function check tree is balnced or not
        int balanced= getHeight(root->left) - getHeight(root->right);//(left height - right height)
        //if balanced > 1 than we have to balance on left (either can ve LL or LR)
        //if balanced < -1 than we have to balance on right (either RR or RL);
        
        //balance on left (either LL or LR)
        if(balanced>1 && root->left->data > key){
            
            return rightRotation(root);
        }
            
            else if(balanced>1 && root->left->data < key){
                //L R as root->left->data < key  , key will add on right and unbalancening will be due to R
                
                //rotate mid (child) to left than rotate top(root) to right
                
                //rotate mid(child) to left
                root->left=leftRotation(root->left);
                //rotate top(root) right
                return rightRotation(root);
            }
        
        else if(balanced<-1 && root->right->data < key){//balance on right (either RR or RL)
            return leftRotation(root);
            }
            
            else if( balanced <-1 &&root->right->data > key){
                //R L as root->right->data > key  , key will add on left and unbalancening will be due to L
                
                //rotate mid (child) to right than rotate top(root) to left
                
                //rotate mid(child) to right
                root->right=rightRotation(root->right);
                //rotate top(root) left
                return leftRotation(root);
            }
        
        else{//when no balancing needed already in balanced state
            return root; //
        }
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends