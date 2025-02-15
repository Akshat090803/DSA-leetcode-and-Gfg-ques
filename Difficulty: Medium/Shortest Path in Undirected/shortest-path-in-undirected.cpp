//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        //We use BFS
        //The Bfs level will be the shortest path to respective vertices
        //whole code similar to bfs
        // for neighbours
        //if(!visted[vertex]){
        //     q.push(vertex);
        //     distance[neighbour] = distance[node]+1; //?IMP 
        // }
        //?for eg distance of reaching node is x .For reaching neighbours of node ffrom surce , distance will be diantance[node]+1 = x+1 
        //initialize diatnce arr with -1; as for nodes we can't visit from sorce will have distance -1
        //?don't run loop for unvisited nodes/unreachable nodes ,as thir distance will be -1 acc to ques
        
         vector<int>distance(adj.size(),-1);//initialize with -1;
         queue<int>q;
         vector<int>visited(adj.size(),0); //visited arr
         
         q.push(src); //push source as it will be starting node
         distance[src]=0; //mark distance of src 0 as there will be 0 distance for src to  reach itself i.e, src is at 0 distance to itself
         visited[src]=1; //mark src visited
         while(!q.empty()){
             int node=q.front();
             q.pop();
             
             //visit neighbours
             for(int j=0;j<adj[node].size();j++){
                 int neighbour=adj[node][j];
                 
                 if(!visited[neighbour]){
                     visited[neighbour]=1;
                     distance[neighbour]=distance[node]+1;
                     //diatnace of neighbour will be one more than their parent
                     q.push(neighbour);
                 }
             }
         }
         
         
        return distance;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends