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
  
  bool childExist(int ind,int n){
      return ind<n;
  }
    bool isHeap(struct Node* tree) {
        // code here
        queue<Node*>q;
        q.push(tree);
        vector<int>levelorder;
        while(!q.empty()){
            Node*top=q.front();
            q.pop();
            levelorder.push_back(top->data);
            
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        
        bool left=true,right=true;
        int n=levelorder.size();
        bool heap=true;
        
        for(int i=0;i<n;i++){
            
            int leftChild=i*2+1;
            int rightChild=i*2+2;
            left=childExist(leftChild,n);
            right=childExist(rightChild,n);
            
            if(leftChild>=n && rightChild>=n){
                left=false;
                right=false;
                
            }
            else if(leftChild>=n) {
                left=false;
                heap=false; //means left child not exist only right child exist it violates heap
                break;
                
            }
            else if(leftChild<n && rightChild>=n){
             if(!right){
                 heap=false;
                 break;
             }
             left=true;
             right=false;
            }
            else{
                if(!right){
                    heap=false;
                    break;
                }
                if(levelorder[i]<levelorder[leftChild] || levelorder[i]<levelorder[rightChild]){
                    heap=false;
                    break;
                }
                left=true;
                right=true;
            }
            
           
        }
        
        if(heap) return true;
        return false;
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