//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
  
    void check(Node*root, int low, int high , bool & dead){
        if(root==nullptr || dead) return;
        
        //leaf node . We check for leaf node only as only Leaf Node can be a Dead Node
        if(!root->left && !root->right){
             if(abs(root->data - low)<=1 && abs(root->data-high)<=1){
                 dead=true;
                 return;
             }
        }
        
        //call for left 
        //for left low will be same but high will be root
        check(root->left,low,root->data,dead);
        
        //call for right
         //for right high will be same but low will be root
        check(root->right,root->data,high,dead);
        
    }
    
    bool isDeadEnd(Node *root)
    {
        bool dead=false;
        int low=0;
        int high=10002;//1 <= Value of Nodes <= 10001
        check(root,low,high,dead);
        return dead;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends