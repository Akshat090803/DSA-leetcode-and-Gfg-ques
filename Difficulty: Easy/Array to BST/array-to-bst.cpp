//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

bool help(Node* root, long long int up, long long int l) {
    if (root->data >= up || root->data <= l)
        return false;
    bool ans = true;
    if (root->left)
        ans = help(root->left, root->data, l);
    if (ans && root->right)
        ans = help(root->right, up, root->data);
    return ans;
}

bool isValidBST(Node* root) {
    return help(root, 3147483648, -3147483649);
}

int Height(Node* root) {

    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);

    int rightHight = Height(root->right);

    if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)
        return -1;

    return max(leftHeight, rightHight) + 1;
}

bool isBalanced(Node* root) {

    if (root == NULL)
        return true;

    if (Height(root) == -1)
        return false;
    return true;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
  
   Node* makeBST(vector<int>& nums,int start , int end){
       if(start>end) return nullptr;
       //for balanced BST we make node from mid of the arr
       int mid= start+(end-start)/2;
       Node*temp=new Node(nums[mid]);
       
       //left
       //all the ele before mid will on left part as they all are small than nums[mid]
       //so arr for left will be from start to mid-1
       temp->left= makeBST(nums, start,mid-1);
       
       //Right
       //all the ele after mid will on right part as they all will be greater than nums[mid]
       //so arr for right will be from mid+1 to end
        temp->right= makeBST(nums,mid+1,end);
        
        return temp;//return address of the node created
      
   }
    Node* sortedArrayToBST(vector<int>& nums) {
        
        Node*root= makeBST(nums,0,nums.size()-1); //start=0 end =nums.size()-1
        
        return root;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        Node* a = ob.sortedArrayToBST(arr);
        vector<int> v;
        inorder(a, v);

        if (!isValidBST(a) or v != arr) {
            cout << "false" << endl;
            return 0;
        }
        bool f = isBalanced(a);

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends