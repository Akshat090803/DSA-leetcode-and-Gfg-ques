//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
       
       
       //!Way-1 Time-O(N^2)  we will get Time limit exceeded
       
       //first create a vector of pair of(profit , deadline)  which will be sorted(in descending order) on basis of profit
       
       vector<pair<int,int>>jobs;
       for(int i=0;i<deadline.size();i++)
       jobs.push_back({profit[i],deadline[i]});
       
       //sort in descending order
    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
       //or we can create a comparision func and pass it here
       
       int maxDeadline=0; //for creating task array which tells whether slot is taken or not
       for(auto x:deadline)
       maxDeadline=max(maxDeadline,x);
       
       vector<bool>Task(maxDeadline+1,0); //we will follow 1 based indexing in TAsk arr
       //why 1 based indexing so that deadline 4 we can do TAsk[4]=1 ;
       //else we have to do -1 each time for accessing TAsk arr value correctly if we follow 0 based indexing
       
       vector<int>ans(2,0); //?ans[0] => count ans ans[1]=profit
       
       for(auto x: jobs){
           
           //try searching slot form jobs deadline slot in TAsk arr and move for left if slot is occupied.
           //for eg job with dealine 4 can be done in slot 4 or 3 or 2 or 1 . SO first check in 4 than if occupied go for 3 than 2 so on..
           for(int j=x.second ;j>0;j--){
               
               //when slot is empty
               if(Task[j]==0){
                   Task[j]=1;
                   ans[0]++;
                   ans[1]+=x.first;
                   break;
                   
               }
           }
       }
       
       return ans;
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends