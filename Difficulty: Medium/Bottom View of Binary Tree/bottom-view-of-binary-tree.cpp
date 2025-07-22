//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
   //func find posiiton of left most and right most node
    void find_l_r(Node*root,int& l,int& r,int pos){
        if(root==nullptr) return;
        
        l=min(l,pos);//we take min as in left we are going(pos) 0 than -1 than -2.So left most node will have most minimum value
        r=max(r,pos);//we take max as in right we are going(pos) 0 than 1 than 2 so right most node will have most maximum value
        
        //call for left
        find_l_r(root->left,l,r,pos-1);//pos-1 as we going left 0 than -1 than -2
        //call for right
         find_l_r(root->right,l,r,pos+1);//pos+1 as we going right 0 than +1 than +2
        
    }
     //!way-2 using recursion
    void Bview_Rec(Node*root,vector<int>& ans,vector<int>& level,int pos,int curr_level){
        if(root==nullptr) return ;
        
        if(curr_level>=level[pos]){//if greater level is there in vertical aligned nodes
            level[pos]=curr_level;
            ans[pos]=root->data;
        }
        
        //left
        Bview_Rec(root->left,ans,level,pos-1,curr_level+1);
        //right
        Bview_Rec(root->right,ans,level,pos+1,curr_level+1);
        
    }
    
    vector <int> bottomView(Node *root) {
          //!way-2 using recursion
        //we instead of index we keep track of level bcoz only node of max level(lower most level) will be part of bottom view so update if greater level node come for virtical aligned nodes
        //like way-1 we first find l,r for size of arr and starting pos(-1*l)
        int l=0,r=0;
        find_l_r(root,l,r,0);
        int pos=-1*l;
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MIN);//iniitlazed with INT_MIN as maximum most level will get stored
        int curr_level=0;
        Bview_Rec(root,ans,level,pos,curr_level);
        return ans;
    }
};
