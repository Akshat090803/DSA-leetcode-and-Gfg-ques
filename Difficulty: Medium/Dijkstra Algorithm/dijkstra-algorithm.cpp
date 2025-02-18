//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        //!There are two ways
        //?Way-1 without priority queue (Just using vector)
        //time ->O(V^2)
        //space O(v)
        //usecase->use when graph is dense
        
        //!Way-2 (Using Priority queue)
        //in way 1 time is increasing because in each iteration we are looking for minimum distance node in array which increse time
        //As we need minimum in each iteration ,We can use Min-heap
        //Time-> O (ELogE)  
        //If graph is complete graph than E=V^2 so O(ELogV^2) ~ O(ELogV)
        //Space -O(E) space is not v but E beacuse in pq , a single vertice is present multiple times
        
        
        //!Way-1
        int v=adj.size();
        vector<bool>explored(v,0);
        vector<int>dist(v,INT_MAX);
        //src to src distance will be 0 and it is confirmed so 
        dist[src]=0;
        
        //we have to find distance for v nodes so run loop v times
        int count=v;
        while(count--){
            
            //find the unexplored node which has minimum distance
            //in way-2 we will use priority queue to avoid this step
            int node=-1 , value=INT_MAX;
            for(int i=0;i<v;i++){
                if(!explored[i] && dist[i]<value){
                    value=dist[i];
                    node=i;
                }
            }
            //mark the unexplored node which has minimum distance as explored because now it is confirm that it has shortest distance form src
            explored[node]=1;
            
            //visite neighbours
            for(int j=0;j<adj[node].size();j++){
                int neighbour=adj[node][j].first;
                int weight=adj[node][j].second;
                //if neighbour is unexplored and its new distance from node ie, (dist[node]+weight) is smaller than curr dist of neighbour than update neighbour distance  i.e, its distance is not conforimed that it is shortest
                if(!explored[neighbour] && dist[node]+weight < dist[neighbour]){
                    dist[neighbour]=dist[node]+weight;
                }
            }
            
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends