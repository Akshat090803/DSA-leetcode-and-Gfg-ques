//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
/*Complete the function below
Node is as follows:
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
    // Function to check if two nodes are cousins in a tree
    //if parent of x and y are in same level than their child will also in same layer that is at next level of their parent for eg. parent of x and y both are found in level 1 than x and y will be present in same level that is level 2 as x and y are child of parent they will be at next level
    bool isCousins(Node* root, int x, int y) {
        //edge case when either of x or y is root node than other will not at same level so can't be cousin so false
        if(root->data==x || root->data==y) return false;
        
        queue<Node*>q;
        Node*p1=nullptr;//represent parent node of x
        Node*p2=nullptr;//represent parent node of y
        q.push(root);
        while(!q.empty()){
            int n=q.size();//tells us how many nodes at current level
            while(n--){//iterating all nodes of current level
                Node*temp=q.front();
                q.pop();
                if(temp->left){//if left child exist
                    if(temp->left->data==x) p1=temp;//check temp is parent of x
                    else if(temp->left->data==y) p2=temp;//else check temp is parent of y
                    q.push(temp->left);
                }
                
                if(temp->right){//if right child exist
                    if(temp->right->data==x) p1=temp;//check temp is parent of x
                    else if(temp->right->data==y) p2=temp;//else check temp is parent of y
                    q.push(temp->right);
                }
            }
            //parent of one is found and parent of another not found
            if((p1 && !p2) || (p2 && !p1)) return false;//it means x and y are not at same level.If they are at same level than we must have found parents for both x and y
            
            else if(p1 && p2){//p1 and p2 both exist means x and y both are at same level as we have found parents for both in above above while loop  while(n--)
                if(p1==p2) return false;//if x and y both have same parent then they are not cousin
                else return true;//when they have diffrent parent return true
            }
            
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    Solution solution;
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        cout << solution.isCousins(root, x, y) << endl;
        cout << "~" << endl;
    }
    return 1;
}
// } Driver Code Ends