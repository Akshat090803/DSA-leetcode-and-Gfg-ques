class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>v; //end time , start time
        
        for(int i=0;i<start.size();i++){
        v.push_back({end[i],start[i]});
        }
        
        sort(v.begin(),v.end());
        
        int count =1;
        int endTime=v[0].first;
        
        for(int i=1;i<v.size();i++){
            if(endTime < v[i].second){
                count++;
                endTime=v[i].first;
            }
        }
        
        return count;
        
    }
};