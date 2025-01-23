//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        //we want minium sum/cost
        //there can be three ways for cost -> we add max- max values but by this we will not get m get minimum totatl cost
        //we add max and min value but by this also we will not getn minumm total cost
        //thirs is we add minum minimum value. By this we will get mimimum total cost
        //if we see example 2 , it is clear get we sre adding minimum - minimum value 
        
        if(arr.size()==1) return 0 ; //see example 3
        
        //as we will need first two  minium value in each iteration -
        //we can use sorted vector(in descending order) or min heap(priority queue)
        //as we need frequent access to minum ele we will use min-heap
        //we can use soretd arr ind dexneding order also so that we can pop from back at O(1) time
        //we are not useing sorted vector in ascending arr becoz in that we have to pop from front and for poping complexity will not be O(1) if we pop from front
        
        
        //min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int x : arr) pq.push(x); //push in min-heap
        vector<int> cost_store;
        
        while(pq.size()>=2){
            
            int min=pq.top();//frist min
            pq.pop();
            int cost=min+pq.top(); //adding with second min
            pq.pop();
            cost_store.push_back(cost);
            pq.push(cost);
        }
        
        
        int sum=0;
        for(int x:cost_store) sum+=x;
        return sum;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends