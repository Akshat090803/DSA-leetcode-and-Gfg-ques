//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        //we use greedy approach
        //for min_cost we will buy min cost candy and take max cost candy as free
        //for max_cost we will buy max cost candy and take min cost candy as free so that we can have amx_cost at last
        
        //to access min and max cost fo candy we sort the array
        sort(candies,candies+N);
        
        int min_cost=0;
        int max_cost=0;
        
        //for min cost
        int i=0;
        int j=N-1;
        while(i<=j){
            min_cost+=candies[i];
            i++;
            j-=k;
        }
        
        //for max cost
         i=N-1;
         j=0;
        while(i>=j){
            max_cost+=candies[i];
            i--;
            j+=k;
        }
        
        return {min_cost,max_cost};
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends