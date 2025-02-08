//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfsApproach(int node  ,vector<vector<int>>& adj , vector<bool>&visited,stack<int>&st){
        visited[node]=1;//?mark visited
        //don't push in stack here .
        //we will push after visiting all neighbours
        
        //visite neighbours
        for(int j=0;j<adj[node].size();j++){
            int vertex =adj[node][j];
            if(!visited[vertex]){
                dfsApproach(vertex,adj,visited,st);
            }
        }
        
        st.push(node); //now after viisting all neighubours finally push node
        //so that when we pop form stack and push in arr , node(u) will come before neighbours (v) i.e, u will come before v which is required
        
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        //!There are two ways to solve this proble,
        //?way-1 using DFS (Time-O(v+e) space O(v))
        //we use a stack also in it and push node in stack only after visisting all thr neibhbours
        //if we not do so and use array than we have to reverse the arr (in the loop of unvisited vertices) and this will add extra time complexity for reversing
        //so we used stack and pushed node in it while returning fromfunc i.e, after visiting all neighbours
        vector<bool>visited(adj.size(),0);
        stack<int>st;
        vector<int>ans;
        
        //do dfsApproach for all unviisted node as graph can be unconnected
        for(int i=0;i<visited.size();i++){
            
            if(!visited[i]) dfsApproach(i,adj,visited,st);
        }
        
        //transfre ele from stack to arr
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends