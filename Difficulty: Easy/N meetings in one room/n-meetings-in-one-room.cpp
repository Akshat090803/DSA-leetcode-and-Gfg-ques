//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool comp(pair<int,int>a,pair<int,int>b){
    return a.second < b.second;
    //return true if a is smaller than b
    //question ask is a and b at correct posiition
}


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        //we will take meeting whose end time is small
        // so we need to sort end time array along with ist respective start time
        
        vector<pair<int,int>>meeting; // in pair <start,end>
        for(int i=0;i<start.size();i++)
        meeting.push_back({start[i],end[i]});
        
        
        //now sort on basis of end time
        
        sort(meeting.begin(),meeting.end() , comp);
        
        int total=0;
        int ending=-1; 
        for(int i=0;i<meeting.size();i++){
            pair<int,int>currMeet=meeting[i];
            //checking we can conduct this meeting
            //if curr meeting start after the end of previous meeting than we can do curr meeting
            if(currMeet.first > ending){
                total++;
                ending=currMeet.second;
                ///now the ending will be the end time of curr meeting
            }
        }
    
        return total;
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
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends