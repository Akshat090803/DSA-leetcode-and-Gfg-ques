/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        
        if(k==1) return nullptr; //when k=1 we delete all node so head=null
        
        int count=1;
        Node*prev=NULL;
        Node*curr=head;
        
        while(curr!=nullptr){
            //if count=k delete node
            if(count==k){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
                count=1;//reset count to 1 as we have to find next kth node
            }
     
                count++;
                prev=curr;
                if(curr) curr=curr->next;
                
        
        }
        
        return head;
    }
};

