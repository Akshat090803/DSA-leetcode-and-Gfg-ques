//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfsApproach(int node , int parent ,vector<vector<int>>& adj , vector<bool> & visited ){
        visited[node]=1;
        
        //check for neighbouring nodes
        for(int j=0;j<adj[node].size();j++){
            int vertex=adj[node][j];
            if(parent==vertex){
                continue;
            }
            //when veretx is not equal to parent but still visisted means there is a cycle so return true
            else if(visited[vertex]){
                return 1;
            }
            //?when vertex is not equal to parent and vertex is unvisited , make a func call for that vertex
            bool return_value =  dfsApproach(vertex , node , adj,visited);
            
            if(return_value) return 1;
            //if func return true (means cycle is detected so if cycle is detetced ,simply true no need to check further)
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
       //This can be done using DFS as well as BFS
       //Time for both approach is O(V+E)
       //Space for both approach is O(v)
       vector<bool>visited(adj.size(),0);
       
       //this will give all correct output when graph is a connnected graph only
       //?it will give wrong output for unconnected graph see example 2 in which we will not be able to visite all vertices
      //!   return dfsApproach(0,-1,adj,visited); 
    
    //so to visit unvisited vertices also we call it like this
    //?in dfs bfs traversal also ,if graph is unconnected than do like this only
    
       for(int i =0;i<visited.size();i++){
           //it will run for 0 first , and after completing , if any node still reamin unvisited it will start same process from that node 
           if(!visited[i]){
               bool return_val=dfsApproach(i,-1,adj,visited); 
               if(return_val) return 1;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends