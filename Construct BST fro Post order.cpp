Node* makeBST(int post[],int lower,int upper, int & ind){
    
    //base condition when index go out of bound
    if(ind<0) return nullptr; //as we are going in revrse i.e, ind=arr.size to i=0 
    
    //when ele not in range of lower < ele < upper 
    if( lower > post[ind] || upper < post[ind]) return nullptr;
    
    //in pre order(N L R) we are followinf N LR
    //in post order (L R N) we go in revrse so that to create node first 
    //!so we consider right part first before left part
    
    Node* root= new Node(post[ind]);
    ind--; //we are traversing from end
    
      // Right
     root->right = makeBST(post,root->data,upper, ind);
    // to add on right side, the ele must be in range     root->data < ele <  upper
    // for right upper will be same but lower will be root->data
    
     // left
    root->left = makeBST(post, lower, root->data , ind);
    // to add on left side, the ele mus be in range lower<ele<root->data
    // for left lower will be smae but upper will be root->data

    return root;
    
}

Node *constructTree (int post[], int size)
{ 
        int ind=size-1; //bcoz in Post order root ele is at end of arr
        int upper=INT_MAX;
        int lower=INT_MIN;
        Node*root=makeBST(post,lower,upper,ind);
        return root;

}
