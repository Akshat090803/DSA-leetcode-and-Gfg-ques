
class Solution {
  public:
   class Node {
       public : 
          int freq;
          char ch;
          Node* left;
          Node*right;
          
          Node(int fre , char c){
              ch=c;
              freq=fre;
              left=nullptr;
              right=nullptr;
          }
   };
   
   class comp {
     public :
      bool operator () (Node*a , Node*b){
          return a->freq > b->freq;
      }
   };
   
   void preorder(Node * root , string & temp , vector<string>&ans){
       if(root==nullptr) return;
       
       if(!root->left && !root->right){
           ans.push_back(temp);
           return;
       }
       
    //   /for left
       temp.push_back('0');
       preorder(root->left,temp,ans);
       temp.pop_back();
       //for right
       temp.push_back('1');
       preorder(root->right,temp,ans);
       
      temp.pop_back();
       }
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
      
      
      priority_queue<Node * , vector<Node*> , comp>pq;
      
      for(int i=0;i<N;i++){
          Node * newNode = new Node(f[i], S[i]);
          pq.push(newNode);
      }
      
      while(pq.size()>1){
          Node * first = pq.top();
          pq.pop();
          Node * second=pq.top();
          pq.pop();
          
          Node * newNode= new Node(first->freq + second->freq,'$');
          newNode->left=first;
          newNode->right=second;
          
          pq.push(newNode);
      }
      
      Node * root = pq.top();
      
      string temp;
      vector<string>ans;
      
      preorder(root, temp , ans);
      
      return ans;
    }
};