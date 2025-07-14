/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

         if(head->next==nullptr) return head;
         
         Node*prev=head;
         Node*curr=head->next;
         while(curr){
             
             if(prev->data!=curr->data){
                 prev=prev->next;
                  prev->data=curr->data;
                 
             }
            
                   curr=curr->next;
         }
         
         prev->next=nullptr;
         
         return head;
        
    }
};