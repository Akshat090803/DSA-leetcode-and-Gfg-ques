/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* first=new Node(0);
        first->next=head;
        head=first;
        
        //first is already pointing to Head
        Node*second=head->next;
        Node*prev=head;
        Node* curr=second;
        int kc=k;
        while(curr!=nullptr){
            prev=first;
            curr=second;
            
            kc=k;
            while(kc-- && curr!=nullptr){
                Node*future=curr->next;
                curr->next=prev;
                prev=curr;
                curr=future;
            }
            
            first->next=prev;
            second->next=curr;
            first=second;
            second=curr;
        }
        
         Node*dummy=head;
        head=head->next;
        delete dummy;//deleting dummy node
        return head;
    }
};