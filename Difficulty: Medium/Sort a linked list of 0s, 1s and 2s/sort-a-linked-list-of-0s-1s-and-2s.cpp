/*  Node is defined as
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
    Node* segregate(Node* head) {
        // code here
        int count0 = 0;
  int count1 = 0;
  int count2 = 0;

  Node *temp = nullptr;
  while (head != nullptr)
  {
      if(head->data==0)
        count0++;
      else if(head->data==1)
      count1++;
      else
      count2++;

      temp=head;
      head=head->next;
      delete temp;  //We are deleting nodes of original list also
      
  }

  temp = new Node(3); //dummy node
  Node * tail=temp;
  //Creating New nodes with value 0
  while (count0--)
  { 
    
    tail->next=new Node(0);
    tail=tail->next;
  }
  //Creating New nodes with value 0
  while (count1--)
  {
     tail->next=new Node(1);
    tail=tail->next;
  }
  //Creating New nodes with value 0
  while (count2--)
  {
     tail->next=new Node(2);
    tail=tail->next;
  }

   head=temp->next;
   delete temp;
   return head;
    }
};