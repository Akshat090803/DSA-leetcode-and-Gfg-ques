//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    setHeights(root);
    return root;
}

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

struct Node* deleteNode(struct Node* root, int data);

int main()
{
	int t;
	cin>>t;
	getchar();

	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root = buildTree(s);
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	
cout << "~" << "\n";
}
	return 1;
}

// } Driver Code Ends


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

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
      
      root->height=1+ max(getHeight(root->left),getHeight(root->right));
      child->height=1+ max(getHeight(child->left),getHeight(child->right));
      return child; //as now child act as a root
  }
  
  //!Left Rotaion
  Node* leftRotation(Node*root){
      Node * child=root->right;
      Node*childLeft=child->left;
      
      child->left=root;
      root->right=childLeft;//left child of child node will attch to right of root
     
      root->height=1+ max(getHeight(root->left),getHeight(root->right));
      child->height=1+ max(getHeight(child->left),getHeight(child->right));
      return child; //as now child act as a root
  }
  

Node* deleteNode(Node* root, int key)
{
   //Deletion of AVL TREE is simlar to BST deltion
   //But while returning we have to check for balancing just like we doing in insertion
  //Logic for L and R is same but for choosing next i,e, whether it will be LL or Lr or RR or RR is different then insetion
  //?Here we are shortning the deletion code for when two child exist
  //in Here we will replace the greatest node from left with root
  //than again make a call for deleting the curr node(rightmost node from left)
  //or we can use previous method also that we were doing in BST or same method can be used in BST also 
  //in this method we are replacing node where as in previous method we were delting the node
  
  
  if(root==nullptr) return nullptr;
  
  if(key < root->data){
      root->left=deleteNode(root->left,key);
  }
  else if(key > root->data){
      root->right=deleteNode(root->right,key);
  }
  else{//when root==key;
  
  //1) leaf node
  if( !root->left && !root->right){
      delete root;
      return nullptr;
  }
  //root has only One Child
  else if(root->left && !root->right){//root has only left child
      Node*temp=root->left;
      delete root;
      return temp;
  }
  else if(root->right && !root->left){//root has only right child
      Node*temp=root->right;
      delete root;
      return temp;
  }
  //when Both child exist
  else{
      //we are using different way then the way used in BST 
      //we can use BSt way also and vice versa use this way in BSt also 
      Node*curr=root->left;
      while(curr->right){//going to right most node
          curr=curr->right;
      }
      
      //replace root by data of right most Node
      //in previous method we we also doing same but we actually moved right most node to root positon
      root->data=curr->data;
      root->left=deleteNode(root->left,curr->data);//IMP
      //make a call to delete curr node (right most node from left)
      //or we can use while loop to reach right most node and delete that node 
  }
      
  }
  
  //update height
  root->height=1+max(getHeight(root->left),getHeight(root->right));
  //Now check for balancing
  int balanced_1=getHeight(root->left)-getHeight(root->right);
  
  //L
  if(balanced_1>1){
      Node*mid=root->left;
      int balanced_2=getHeight(mid->left)-getHeight(mid->right);
      //LL
      if(balanced_2>=0){
          rightRotation(root);
      }
      //L R when balanced_2 is less than 0 strict negative
      else{
          root->left=leftRotation(root->left);//L
          return rightRotation(root);//R
      }
  }
  //R
  else if(balanced_1<-1){
       Node*mid=root->right;
      int balanced_2=getHeight(mid->left)-getHeight(mid->right);
      //RR
      if(balanced_2 <= 0){
          leftRotation(root);
      }
      //R L when balanced_2 is greater than 0 strict positive
      else{
          root->right=rightRotation(root->right);//R
          return leftRotation(root);//L
      }
  }
  else return root;  //when already balanced root gets returned
  
}
