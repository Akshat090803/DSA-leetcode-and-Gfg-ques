//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
       
       //Just like in tree tarversal BFS (Level -order) we used queue , here also we will use queue
       //we will keep care that no vertice is visited twice i.e, vertice should not be pushed in queue more than one time
       //so for this we will use one array visisted to keep tract of visit
       //time -> V+2E ~ O(V+E) 
       //space O(v) in visistd arr will be size v and in queueu also we are psuhing vertice only for one time , the max size of the queuue will be v when there is micelle like structure all nodes connected to single node
       
       int v=adj.size(); //count of vertices
       queue<int> q;
       vector<bool>visited(v,0);//iniitlaize to 0 means initially all are unvisited
       q.push(0);//iniitally push the first node from where we start traversal
       visited[0]=1;//mark vsited
       
       vector<int>ans;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           ans.push_back(node);
           
           //traverse all edges associated with that vertice in the list
           for(int j=0;j<adj[node].size();j++){
               
               int curr_vertex=adj[node][j];
               //if edge is unvisited
               if( !visited[curr_vertex]){
                   visited[curr_vertex]=1;//mark the edge visited;
                   q.push(curr_vertex); //push node in queue
               }
           }
       }
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends