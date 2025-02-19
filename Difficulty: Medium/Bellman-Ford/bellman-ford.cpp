//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Bellamn Ford Algo
        //!Time worst case -> O(v*e)
        //!Best case Time -> O(E) 
        //Space -> O(v)
        
        //Belamn ford algo is applied to onnly directed graphwhich have negative weights
        //Neagtive cycle->if there is a cycle and sum of all weights in a cycle is negative than it is negative cycle
        //No algorithm can find shortest distance for negatve cucle graph evn bellman forn can't
        
        //?Bellman Ford algo gives shortest distance for graph where negative weights are present
        //?ANd can detetct negative cycles also
        
        vector<int>dist(V,1e8); //vertices can't be reach from the s then mark the distance as 10^8.
        dist[src]=0; //src to src distance is 0
        
        int E=edges.size();
        
        //realx the edges for v-1 times
        for(int i=0;i<V-1;i++){
            bool distChange=false;
            
            for(int j=0;j<E;j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                
                //edge case skip iteration
                if(dist[u]==1e8)
                continue;
                //dist[u]==1e8 means there we have not find any distance from src to u yet
                //and as we are not able to reach from src to u than how we can reach from u to v
                //menas dist[u]1e8 means src->u has no path yet than how we can go src->u->v
                
                
                // else
                if(dist[u]+wt < dist[v]){
                    dist[v]=dist[u]+wt; //update dist
                    distChange=true; //atleast one dist is updated
                }
                
            }
            
            if(distChange==false) return dist;
            //menas if distance not updated for atleast once , means all have assigned their shortest distances so return dist
            //this step is for best case time complesxity that is we have found shortest distances in one itertaion why to run loop for v-1 times
        }
        
        
        //detetct cycle
        //after relaxing edges for v-1 times relax edge one more time
        //if distance gets updated means there is a negative cycle present in the graph so return {-1}
         for(int j=0;j<E;j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                
                //edge case skip iteration
                if(dist[u]==1e8)
                continue;
                //dist[u]==1e8 means there we have not find any distance from src to u yet
                //and as we are not able to reach from src to u than how we can reach from u to v
                //menas dist[u]1e8 means src->u has no path yet than how we can go src->u->v
                
                
                // else
                if(dist[u]+wt < dist[v]){
                    
                    vector<int>path;
                    path.push_back(-1);
                    return path;
                    //return {-1} as distance is updated
                }
                
            }
            
            return dist;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends