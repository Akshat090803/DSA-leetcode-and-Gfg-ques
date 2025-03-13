//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(pair<int,int>p1,pair<int,int>p2){
   float ratio1 = (float)p1.first / (float)p1.second;
    float ratio2 = (float)p2.first / (float)p2.second;
    
    return ratio1>ratio2;
}

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        vector<pair<int,int>>wt_val;
        for(int i=0;i<val.size();i++){
             wt_val.push_back({val[i],wt[i]});
        }
        //first sort arr on basis of value/weight in descending order
        //as array val_wt arr is of type pair<int,int>t
        //we will pass custom comparision func in sort func which sort on basis of value/weight
        
        sort(wt_val.begin(),wt_val.end(),comp);
        int i=0;
        double maxValue=0;

        while(capacity && i<wt_val.size()){
            
            double wt_curr=wt_val[i].second;
            double val_curr=wt_val[i].first;
            
            if(wt_curr<=capacity){
                 maxValue+=val_curr;
                 capacity-=wt_curr;
                 
            }else{
                //when wt_curr is greater than capaocity...
                //than we have to push fractional part
                double fractional=(capacity/wt_curr)*val_curr;
                maxValue+=fractional;
                capacity=0;//as fractional part will comletely fill the bag so capacity become 0
                break;
            } 
            i++;
        }
        
        
        return maxValue;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends