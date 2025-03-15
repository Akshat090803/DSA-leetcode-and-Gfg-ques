class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
        //push all the non overlapping intervals
        while(i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

//if i becomes n, measn all were not overlapping with newInterval ,so newInterval will be added at last
        if(i==n){
            ans.push_back(newInterval);
            return ans;
        }

        //merge overlapping intervals
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        
        ans.push_back(newInterval);

        //for left over intervals after merging
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};