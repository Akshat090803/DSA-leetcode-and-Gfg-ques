//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct LNode {
    int data;
    struct LNode* next;

    LNode(int x) {
        data = x;
        next = NULL;
    }
};

struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;

    TNode(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// } Driver Code Ends
/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    
    TNode * makeBST(vector<int>&arr,int low,int high){
           
           if(low>high) return nullptr;
           
           int mid=(low+(high-low+1)/2); // we take ceil value as if you see example when mid comes for eg 2.4 they are taking as 3(ceil) instead of 2
           //or you can do likke this also mid=low+(high-low + 1)/2;
           
           //Create NODE
           TNode* root= new TNode(arr[mid]);
           
           //left
           root->left=makeBST(arr,low,mid-1); //for left high will be mid-1
           
           //right
           root->right=makeBST(arr,mid+1,high); //for right low will be mid+1
           
           return root;
           
    }
    TNode *sortedListToBST(LNode *head) {
        //create a arr and push ele of linked list in arr
        //now we have a sorted arr and we have previously solved how to make balanced BST from sorted arr
        
        vector<int>arr;
        while(head){
            arr.push_back(head->data);
            head=head->next;
        }
        
        int low=0; 
        int high=arr.size()-1;
        
        return makeBST(arr,low,high);
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
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        LNode* head = new LNode(data);
        LNode* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new LNode(data);
            tail = tail->next;
        }

        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends