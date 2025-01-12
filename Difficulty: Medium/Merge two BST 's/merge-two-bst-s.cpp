//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void Inorder(Node*root,vector<int>&ans){
        if(root==nullptr) return;
        //l
        Inorder(root->left,ans);
        //N
        ans.push_back(root->data);
        //R
        Inorder(root->right,ans);
    }
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // store inorder traversal of tree1 in arr1
        //store inorder traversal of tree2 in arr2
        //now we have two sorted arr arr1 and arr2
        //we know how to merge two sorted arr so merge arr1 and arr2 and return merged arr
        
        vector<int>arr1;
        vector<int>arr2;
        Inorder(root1,arr1);
        Inorder(root2,arr2);
        
        //merge arr1 and arr2
        int i=0,j=0;
        vector<int>merged_arr;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                merged_arr.push_back(arr1[i]);
                i++;
            }
            else{
                merged_arr.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<arr1.size()){
            merged_arr.push_back(arr1[i]);
           i++;
        }
        
        while(j<arr2.size()){
             merged_arr.push_back(arr2[j]);
            j++;
        }
        
        return merged_arr;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends