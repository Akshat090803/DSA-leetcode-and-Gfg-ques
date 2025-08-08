// User function template for C++

class Solution {
  public:
  
   void Dfs(int node,vector<int> adj[],vector<vector<int>>&ans,vector<bool>&visited, vector<int>&disc, vector<int>&low , stack<int>&st,vector<bool>&inStack,int & timer)
    {
        disc[node]=low[node]=timer;
        visited[node]=1;
        st.push(node);
        inStack[node]=1;
        
        for(int j=0;j<adj[node].size();j++ ){
            int neigh=adj[node][j];
            
            if(visited[neigh]){
                
               if(inStack[neigh]) {
                   low[node]=min(low[node],disc[neigh]);
               }
            }
            else{
                timer++;
                Dfs(neigh,adj,ans,visited,disc,low,st,inStack,timer);
                
                low[node]=min(low[node],low[neigh]);
            }
        }
        
        if(low[node]==disc[node]){
            vector<int>temp;
            while(!st.empty()){
                 int tp=st.top();
                temp.push_back(tp);
               
                st.pop();
                inStack[tp]=0;
                if(tp==node) break;
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    }
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        vector<vector<int>>ans;
        
        vector<int>disc(V);
        vector<int>low(V);
        vector<bool>visited(V,0);
        stack<int>st;
        vector<bool>inStack(V,0); // to let us know the ele is in stack or not
        int timer=0;
        for(int i=0;i<V;i++){
            if(!visited[i]) Dfs(i,adj,ans,visited,disc,low,st,inStack,timer);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};