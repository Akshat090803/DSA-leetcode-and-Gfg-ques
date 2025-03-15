//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
     
     
	public:
	class Node{
	    public:
	       int freq;
	       char ch;
	       Node*left;
	       Node*right;
	       
	       Node(int fre,char c){
	           left=right=nullptr;
	           freq=fre;
	           ch=c;
	       }
	};
	
		class comp{
	    public:
	     bool operator()(Node*a,Node*b){
	         //is a smaller than b
	       //  return Node*a->freq < Node*b->freq;
	       //?but in heap we take opposite comparison sign 
	       //so instead of return Node*a->freq < Node*b->freq; for min heap we take..
	       return a->freq > b->freq;
	     }
	};
	

	
	void preorder(Node*root,vector<string>&ans,string&temp){
	     if(!root)
	     return;
	     
	     //leaf node
	     if(!root->left && !root->right){
	         ans.push_back(temp);
	         return;
	     }
	     
	     //Left
	     temp+='0';
	     preorder(root->left,ans,temp);
	     temp.pop_back();
	     //right
	     temp+='1';
	     preorder(root->right,ans,temp);
	     temp.pop_back();
	     
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    
		    //!create Huffman tree
		    
		    //we are merging first-two smallest  nodes and creating a new node for huffman tree
		    //so to get smallest nodes in each iterration we will use Min heap
		  
		     priority_queue<Node*,vector<Node*>,comp>pq;
		     //instead of greater<type> we passed custom comparison class
		    
		    
		    //iniitlaize minHeap
		    for(int i=0;i<N;i++){
		        Node*root=new Node(f[i],S[i]);
		        pq.push(root);
		    }
		    
		    //merging two smaller node each time and creating new node
		    //?stop when only single node present inside pq .Means all nodes are merged and single node (root node) left which is the root node of huffman tree
		    while(pq.size()>1){
		        Node*first=pq.top();
		        pq.pop();
		        Node*second=pq.top();
		        pq.pop();
		        
		        Node*root= new Node(first->freq+second->freq,'$');//as these node will not be a leaf node ,so tae their char be '$' ,'$' is just for Node constructor parameter not give error ,of Node ,There is no role of '$'
		        root->left=first;
		        root->right=second;
		        // node which occurs at first will be taken on the left of Binary Tree and the other one to the right,
		        
		        pq.push(root);
		    }
		    
		    
		    Node*root=pq.top();
		    pq.pop();
		    
		    //preorder traversal;
		    string temp="";
		    vector<string>ans;
		    preorder(root,ans,temp);
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends