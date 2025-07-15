// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        
        Node* prev=nullptr;
        Node*first=nullptr;
        Node*second=nullptr;
        Node*curr=head;
        
        int a_copy=a;
        a_copy--; 
        while(a_copy--){
            prev=curr;
            curr=curr->next;
        }
        
        if(prev!=nullptr){
            first=prev;
        }
        
        second=curr;
        
        //reverse
        int times=b-a+1;
        
        while(times--){
            Node*future=curr->next;
            curr->next=prev;
            prev=curr;
            curr=future;
        }
        
        second->next=curr;
        
        if(first){
            first->next=prev;
            return head;
        }
        
        return prev;
        
        
        
    }
};