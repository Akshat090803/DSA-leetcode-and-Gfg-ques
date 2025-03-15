bool comp(vector<int>a,vector<int>b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        //greedy approac

        //if we try to solve by sorting on baiss of start time,we are not getting correct answers

        //so try by soritng on basis of end time
        sort(intervals.begin(),intervals.end(),comp);

        int remove=0;
        int endTime=INT_MIN;
        for(auto x:intervals){

           //when not overlapping mdans endTime of precious is smaller than start time of current ,menas previous one will not overlap in interavl of curr;
            if(endTime<=x[0]){
                endTime=x[1];
            }
            else{
                //when overLapping
                remove++;
            }
        }
        return remove;
    }
};