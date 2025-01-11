//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends


class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    void Inorder(Node*root,vector<int>&ans){
        if(root==nullptr) return ;
        
        Inorder(root->left,ans);
        ans.push_back(root->data);
        Inorder(root->right,ans);
    }
    vector<int> findCommon(Node *r1, Node *r2) {
        
        //we need Common Node in sorted order
        //find inorder traversal of first tree and second tree and store in arr
        //compare value of both arr and push common nodess in final arr
        //as it is possible that in one tree common node is at different position and in another tree ,common node at different pos
        //so we us map also and push ele of one traversal in map 
        
        vector<int>arr1;
        vector<int>arr2;
        
        Inorder(r1,arr1);
        Inorder(r2,arr2);
        
        //map
        unordered_map<int,bool>present;
        for(int x:arr1) present[x]=1;
        
        vector<int>ans;
        for(x:arr2){
            if(present[x]){
                ans.push_back(x);
            }
        }
        
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector<int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 1;
}
// } Driver Code Ends