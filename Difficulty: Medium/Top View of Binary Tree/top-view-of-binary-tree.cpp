/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
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
    void Tview_Rec(Node*root,vector<int>& ans,vector<int>& level,int pos,int curr_level){
        if(root==nullptr) return ;
        
        if(curr_level<level[pos]){//if smalller level is there in vertical aligned nodes
            level[pos]=curr_level;
            ans[pos]=root->data;
        }
        
        //left
        Tview_Rec(root->left,ans,level,pos-1,curr_level+1);
        //right
        Tview_Rec(root->right,ans,level,pos+1,curr_level+1);
        
    }
    
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        //!way-1 by level order traversing
        //first decide the size of the ans array(how many node come in top view)
        //size=right most node position - left most node pos + 1 (r-l+1)
        // int l=0,r=0;
        // find_l_r(root,l,r,0);
        // vector<int>ans(r-l+1);
        // vector<bool>filled(r-l+1,0);//in top view the first arrving node in vertical direction will come as node below it will be hide by the node above it so will not come in top view
        // //so filled arr to keep to store topmost node only
        // queue<Node*>q;//to keep track of child and parent
        // queue<int>indexq;//for index of child amd parent so that we can psuh nodes in ans arr accordindgly
        
        // int pos= -1*l;//the left most node is at l pos and l will be l<=0.
        // //We traverse form root node hence root node will come at index -1*l i.e, (-l) in ans arr bcoz the left  most node come at index 0 second left most at index 1
        // q.push(root);
        // indexq.push(pos);
        // while(!q.empty()){
        //     Node*temp=q.front();
        //     pos=indexq.front();
        //     indexq.pop();
        //     q.pop();
        //     if(filled[pos]==0){//if unfilled 
        //         filled[pos]=1;
        //         ans[pos]=temp->data;
        //     }
            
        //     //left
        //     if(temp->left){
        //         q.push(temp->left);
        //         indexq.push(pos-1);//for left index pos-1
        //     }
        //     //right
        //     if(temp->right){
        //         q.push(temp->right);
        //         indexq.push(pos+1);//for rightt index pos+1
        //     }
        // }    
        // return ans;
        
        //!way-2 usinf recursion
        //we instead of index we keep track of level bcoz only node of minimum level(upper most level) will be part of top view so update if minimum level node come for virtical aligned nodes
        //like way-1 we first find l,r for size of arr and starting pos(-1*l)
        int l=0,r=0;
        find_l_r(root,l,r,0);
        int pos=-1*l;
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MAX);//iniitlazed with INT_MAX as minimum most level will get stored
        int curr_level=0;
        Tview_Rec(root,ans,level,pos,curr_level);
        return ans;
        
    }
};

