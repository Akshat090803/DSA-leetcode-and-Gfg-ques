class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        //!It will be solved using Topological sort as there is dpendecy /prerequisite of nextCourse on previouCourse

        vector<vector<int>>adj(n);
        //courses are labeled form 1 to n but we use 0-based indexing for ease so we will subtract -1 from labels so that vertices start from 0

        for(auto x : relations){
            int prevCourse = x[0]-1; //-1 so that certices start from 0 i.e, 1 will becom 0
            int nextCourse=x[1]-1;

            adj[prevCourse].push_back(nextCourse);
        }

        vector<int>inDeg(n,0);
        for(auto x : adj)
        for(auto y: x) inDeg[y]++;

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0) q.push(i);
        }
         vector<int>completionTime(n,0);
        int totalTime=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
             completionTime[node]=completionTime[node]+time[node];// // Add the course's own time
             totalTime=max(totalTime,completionTime[node]);//// Update total time with so that maxTime will store

            //check Neighbourse
            for(int j=0;j<adj[node].size();j++){
                int vertex=adj[node][j]--;
                inDeg[vertex]--;
                completionTime[vertex]=max(completionTime[vertex],completionTime[node]); //!Imp
                if(inDeg[vertex]==0){
                    q.push(vertex);
                }
            }
        }

        return totalTime;
        
    }
};