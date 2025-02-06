//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node ,vector<vector<int>>& adj , vector<bool> &visited , vector<int> & ans){
        //as we are are making call for nodes which are unvisited so without checking in visited arr push them in ans and mark them visited
        visited[node]=1;
        ans.push_back(node);
        
        //recursive call
        for(int j=0;j<adj[node].size();j++){
            int vertex=adj[node][j];
            
            //if beighbour node unvisited make a recursive call for it
            //don't mark as visited as when recursive func for that call start at first stamenet it makes visited[node]=1.So don't mark visited it here
            if(!visited[vertex]){
                dfs(vertex,adj,visited,ans);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        //?Space-O(v) and Time- O(v+e)
        //!way-1 using recursion
        int v=adj.size();
        vector<bool>visited(v,0);
        vector<int>ans;
        int node=0;//starting node
        dfs(node,adj,visited,ans);
        return ans;
        
     
       
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends