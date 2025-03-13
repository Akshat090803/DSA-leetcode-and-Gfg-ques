class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<pair<int,pair<int,int>>>process; //<enqueue,{time,name} >
        for(int i=0;i<tasks.size();i++){
         process.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        
        vector<int>ans;

        // sort on basis of enque time
        //so that we can get enque time od processes in ascending order

        sort(process.begin(),process.end());

        //create a minHeap whuch will return minmum Processing time wala Task out of all avaialble tasks at that time
        //in heap we don't need of enque time,
        //we need procees time (for comparision) and process name for ans vector

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        long long timer=process[0].first; //iniitialize timer with enque time of first task that arrived 
        //suppose if we intilaise timer with 0 but first task to arrive is at 100 , than we are running loop form 0 to 99 unneccessary .So intiiaze timer with the eqnue time of first task

//run until all tasks not completed

int track=0;
        while(ans.size()!=tasks.size()){
            
            //pushing in pq
            while( track<process.size() && process[track].first<=timer){
                int proccTime=process[track].second.first;
                int proccName=process[track].second.second;
                pq.push({proccTime,proccName});
                track++;
            }

            if(!pq.empty()){
                auto executeTask=pq.top();
                pq.pop();
                timer+=executeTask.first;
                ans.push_back(executeTask.second);
            }
            else{
                timer=process[track].first;
            }
        }

        return ans;
    }
};