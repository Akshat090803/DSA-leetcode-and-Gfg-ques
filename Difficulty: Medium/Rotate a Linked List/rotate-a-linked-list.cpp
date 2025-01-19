//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        
        //! We can do this by reversing logic just like we rotate in array
        //reverse whole list
        //than reverse 1st to size-k nodes and 2nd node to size nodes
        
        int size=0;
        Node*temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        
          k=k%size;
         Node*prev=nullptr;
         temp=head;
         
        if(size==1 || k==0) return head; //
        
       
         
         //reach to kth node
         while(k--){
             prev=temp;
             temp=temp->next;
         }
         
         
         prev->next=nullptr;
         
         prev=temp; //go to last node so that rotated list can attach 
         while(prev->next){
             prev=prev->next;
         }
         
         prev->next=head;//attaching first k node(part to rotate)
         
         
         
         return temp;
         
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends