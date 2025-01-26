//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    int size(Node*tree){
        if(!tree) return 0;
        return 1+ size(tree->left) + size(tree->right);
    }
    
    //check Complete Binary tree
    bool CBT(Node*tree,int ind,int nodes){
        
        if(!tree) return 1; // for leaf nodes as their childs will be nullptr 
        
        if(ind>=nodes) return 0;
        
         return CBT(tree->left, ind*2+1 , nodes) &&  CBT(tree->right, ind*2+2 , nodes);
        
    }
    
    bool isHeap(struct Node* tree) {
       
       int nodes=size(tree);
       
       
       if(!CBT(tree,0,nodes)) return 0;
       
        
        //we have checked that given BT is CBT
        //NOw check parent is greate than or equal to its child or not
        bool heap=true;
        
        queue<Node*>q;
        q.push(tree);
        vector<int>levelorder;
        while(!q.empty()){
            Node*top=q.front();
            q.pop();
            levelorder.push_back(top->data);
            
            if(top->left){
                 q.push(top->left);
                 if(top->data < top->left->data){
                     heap=false;
                     break;
                 }
            }
            
            if(top->right) {
                q.push(top->right);
                 if(top->data < top->right->data){
                     heap=false;
                     break;
                 }
                
            }
        }
        
        return heap;
        
       
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends