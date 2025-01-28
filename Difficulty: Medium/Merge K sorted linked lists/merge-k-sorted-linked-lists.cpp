//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Comparision{
    public:
    //for ascending order we do return a <= b; (kya a aur b ka order correct h ie, a b is small h  agr correct he to return 1 else false so that they can swap )
    //for dscending order we do retrun a >= b; (kya a aur b ka order correct he i.e, a b se bigger he to return 1 means correct order else false so that they can swap)
    //?but for minHeap and MaxHeap we revrse the condition of ascending and descending order respectively
    //i.e, for MinHeap condition will be return a > b (opposite of ascedning order  a <= b)
    //for maxHeap condition will be a < b (opposite of decending order cond a>=b)
      bool operator()(Node* a , Node* b){
          return a->data > b->data;
          //is a nad b order CORRET
      }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        
        //!Way-3 of solving this problem using Heap Time-( nklognk or nlogn)
        //!way-1 and way-2 is already covered in previous soln where way-1 is brute force and way-2 is using merge sort
        
        //!in way-3 it is just like kth ele in 2d matrix problem
        //only difference is that we have to add perform action till heap is not empty unlike in kth element in 2d matrix where we to perform while(k--) as we want kth smallest ele
        
        //!here we used customize heap method so that we push nodes in heap and min heap constructed based on nodes
        //i,e, node has two attributes data and next,and how heap know which to take for consideration
    
        //prioirtye queue MIn Heap
        priority_queue<Node*,vector<Node*>,Comparision>pq;
        
        //push arr in it i.em heads of each linked list
        for(auto x: arr) pq.push(x);
        
        Node*head=new Node(-1); //dummy nOde
        Node*tail=head;
        while(!pq.empty()){
            Node*temp=pq.top(); //minumum ele
            pq.pop();//minium ele pop
            tail->next=temp;
            tail=temp;
            
            if(temp->next){ //if next node exist push it in minHeap
                pq.push(temp->next);
            }
        }
        
        return head->next; //we return head->next as head is a dummy node and actual list starts from head->next
        
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends