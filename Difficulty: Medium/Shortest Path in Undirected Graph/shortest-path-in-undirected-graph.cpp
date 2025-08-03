class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> ans(adj.size(),0);
         vector<bool> visited(adj.size(),0);
        queue<int>q;
        q.push(src);
        visited[src]=true;
       
        
        while(!q.empty()){
             int node=q.front();
             
             q.pop();
             for(int i=0;i<adj[node].size();i++){
                 int vertex=adj[node][i];
                 
                 if(!visited[vertex]){
                     visited[vertex]=true;
                     ans[vertex]=ans[node]+1;
                     q.push(vertex);
                 }
             }
        }
        
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0) ans[i]=-1;
        }
        
        return ans;
    }
};