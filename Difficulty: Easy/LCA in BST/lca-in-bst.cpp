//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
    
     void path(Node*root,int target,vector<Node*>&ans,bool &reached){
         if(root==nullptr || reached) return ;
         
         if(root->data==target){
             ans.push_back(root);
             reached =true;
         }
         else if(target<root->data){
             ans.push_back(root);
             path(root->left,target,ans,reached);
         }
         else{ //when target > root->data
              ans.push_back(root);
             path(root->right,target,ans,reached);
         }
     }
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            //!Way1
            //store path to n1 and n2 in differnet arrays
            //?than traverse both arr and ele before first mismatched value is the lowestCommon ANcestor
            bool reached=false;
            vector<Node*>n1Path;
            vector<Node*>n2Path;
            
            //find path of n1
            path(root,n1,n1Path,reached);
            
            //find path of n2
            reached=false;
            path(root,n2,n2Path,reached);
            Node* anc;
            for(int i=0; i<n1Path.size() && i<n2Path.size();i++){
                
                if(n1Path[i]->data!=n2Path[i]->data) break;
                
                anc=n1Path[i]; //we can take n2Path[i] also as ancestor are smae
            }
            return anc;
            
            
        }

};


//{ Driver Code Starts.

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
    
    return root;
}


int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends