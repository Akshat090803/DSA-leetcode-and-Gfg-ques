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
        //as we have inorder traversal node in final arr will be in sorted order
        
        vector<int>arr1;
        vector<int>arr2;
        
        Inorder(r1,arr1);
        Inorder(r2,arr2);
        
        vector<int>ans;
        int i=0 , j=0;
        
        while(i<arr1.size() && j<arr2.size()){
            
            if(arr1[i]<arr2[j]){
                i++; //we can find equal ele in arr1 later 
            }
            else if(arr2[j]<arr1[i]){
                j++;//we can find equal ele in arr2 later 
            }
            else{//when both equal means common
                ans.push_back(arr2[j]); // we have find
                i++;
                j++;
            }
        }
        
        return ans;
        
    }
};
