//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        //!For spanning tree, graph should be connected 
        vector<bool>explored(V,0);
        vector<int>parent(V); //?parennt is justt in case if we wwant to retturn the path also of minium spanning tree
        //we can caalculate cost of minimum spanning tree without  parent also
        //for only cost , we can do without parent also
        
        //min-heap to get min distance node of all
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        //<weight , <node , parent>>
      
        pq.push({0,{0,-1}});
        
        int cost=0;
        
        while(!pq.empty()){
            int node=pq.top().second.first;
            int par=pq.top().second.second;
            int wt=pq.top().first;
            pq.pop();
            
            //if already  explored /part of spanning tree , don't consider again so continue
            if(explored[node])
            continue;
            
            //else when not explored
            cost+=wt;
            explored[node]=1; //mark explored
            parent[node]=par;
            
            //visit neighbpurs
            
            for(int j=0;j<adj[node].size();j++){
                int neighbour=adj[node][j][0];
                int neighbour_wt=adj[node][j][1];
                
                //if neighbour unexplored , push it in pq 
                if( !explored[neighbour]){
                    pq.push({neighbour_wt , {neighbour,node}});
                }
            }
            
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends