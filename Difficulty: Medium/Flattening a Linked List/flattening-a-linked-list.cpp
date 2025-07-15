/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  
  Node* mergeTwoList(Node*head1,Node*head2){
      
      Node* head=new Node(0); //dummy Node
      Node*tail=head;
      while(head1 && head2){
          if(head1->data<head2->data){
              tail->bottom=head1;
              head1=head1->bottom;
          }else{
              tail->bottom=head2;
              head2=head2->bottom;
          }
          
          tail=tail->bottom;
          tail->bottom=nullptr;
      }
      
      if(head1) tail->bottom=head1;
      if(head2) tail->bottom=head2;
      
      return head->bottom;
      
      
      
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
         Node * head=root;
         Node* nextList=head->next;
         
         while(nextList){
             head=mergeTwoList(head,nextList);
             nextList=nextList->next;
         }
         
         return head;
    }
};