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
            // bool reached=false;
            // vector<Node*>n1Path;
            // vector<Node*>n2Path;
            
            // //find path of n1
            // path(root,n1,n1Path,reached);
            
            // //find path of n2
            // reached=false;
            // path(root,n2,n2Path,reached);
            // Node* anc;
            // for(int i=0; i<n1Path.size() && i<n2Path.size();i++){
                
            //     if(n1Path[i]!=n2Path[i]) break;
                
            //     anc=n1Path[i]; //we can take n2Path[i] also as ancestor are smae
            // }
            // return anc;
            
            //! Way-2 without use of Array
            // three case
            //both go right
            //both go left
            //diverge
        
           if(!root) return nullptr;
           
           //both go left
           if(n1<root->data && n2<root->data){
               return LCA(root->left,n1,n2);
           }
           else if(n1>root->data && n2>root->data){//both go right
               return LCA(root->right,n1,n2);
           }
           else{//when they diverge
               //when they diverge , the root from which they diverge will be the lowest common ancestor
               //so return root
               return root;
           }
        }

};
