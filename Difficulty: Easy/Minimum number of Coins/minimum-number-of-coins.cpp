//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    { //we sue greedy approach
    //starts from coin closest smaller to N
    //so we arrange currency in desc as we iterate we will reach closest smaller
    //see how many notes of closest smaller can be used bydoing N/currency[i]
    //how to find closest smaller use n/currency[i] if result >0 menas it is smaller and take result times notes
    //than resuce N value by N%=currency[i] or N=N- count*currency[i] both will work smae
            int currency[]={2000,500,200,100,50,20,10,5,2,1};
            
            int count=0;
            int i=0;
            vector<int>ans;
            while(N){
                
             count=N/currency[i];
             
             //this will not run when count=0 
             while(count--){
                 ans.push_back(currency[i]);
                 N-=currency[i]; //?this or  N%=currency[i]; will work smae but see position where they are used
             }
             
              //N%=currency[i];/?/do this or reduce N-=currency[i] in above while loop while(count--)
             
             // int currency[]={2000,500,200,100,50,20,10,5,2,1};
             //for eg N=43 currency[i]=20 (closest smaller)
             //so no. of coins of 20 43/20 = 2
             //now N will be N%=currency[i] i.e, 43%20 = 3
             //Now N=3 menas 3 ruppes left
             
             //now after 20 , closest smaller for whome N/curency[i] greater than 0 is 2
             i++;
            }
            
            return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends