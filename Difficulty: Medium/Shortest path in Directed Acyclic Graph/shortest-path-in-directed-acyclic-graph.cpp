//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        //This can be done using DFS using current path arr but time will be more
       
       //!If it was unweighted graph i.e, distance is 1 unit for all edges, than we can slve it using nBFS like we were dong in unidrected graph
       
        //Using topological sort
        //as we see let supose vertice x and x has incoming edges from vertices w,y,z;
        //so most suited vertice which give minimum disttance to reach x will be taken among w,y,z
        //so for x, we must first find distance of vertices bfefor x i.,e
        //w->x  ,, y->x ,, z->x , so before x , we must know distance of w,y,z
        //and how do we know we have to find first ditance of w,x,z.So this will be gather by storing the topological sort of graph we will get to know which vertices comes ebfore x
        
        //first create  adjacency list
        vector<vector<pair<int,int>>>adj(V); //pair becuase weight and vertice both will store
        for(auto x:edges)
        adj[x[0]].push_back(make_pair(x[1],x[2]));
        //edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
        
        //!we use DFS method to find topological sort
        //?why?? dfs
        //becuase in ques it is given sorce will be 0 and distance if it is impossible to reach any vertex will be -1
        //so in dfs approach wwe not run outer loop which we run to visit unvisited vertices
        //thats how we will only get topological sort of vertices whicha re accessible from 0
        
        //if we use , Kanhes algo , then indegree for nodes can't visited form src=0 will also have indegree 0 and hence they will also gets included in topological sort as initilly we push all the nodes with inDegree 0
       
        //?how we can find topological sort for this case using Kanhes algo
        //calculate indegree of allvertices
        //?in kanhes algo we initilally push all vertices with indegree 0; by doing so unreachable nodes also gets included in quueue initially as they also have indg=0
        //so initlally we only push 0 in queue as 0 is the src node and its indegree will be 0.By this unreachable nodes will not include in quue nat and hence not in topological sort also
        
        //Lets solve using Kanhe's algo 
        vector<int>inDeg(V,0);
        for(auto x:adj)
        for(auto y:x) inDeg[y.first]++;
        
        queue<int>q;
        
        //!IMP step very  imp
        //reducing inDegree of vertices who have incoming vertices form Unreachable vertices
        //we did this beacuse we are not taking unreachable nodes in tpsort.So reduce unreachable nodes neighbour deg as if not there indeg will never become 0
        for(int i=1;i<V;i++){
            if(inDeg[i]==0){
                for(int j=0;j<adj[i].size();j++){
                    inDeg[adj[i][j].first]--;
                }
            }
        }
        
        q.push(0);//only psh vertice 0 
    
        
        vector<int>tpsort;
        while(!q.empty()){
            int node=q.front();
            tpsort.push_back(node);
            q.pop();
            
            for(int j=0;j<adj[node].size();j++){
                int vertex=adj[node][j].first;
                inDeg[vertex]--;
                if(inDeg[vertex]==0) q.push(vertex);
                
            }
        }
        
        
        //finding distance
        vector<int>dist(V,INT_MAX);
        dist[0]=0; //disnatcne for src to reach src will be 0
        
    for(int i=0;i<tpsort.size();i++){
        int node=tpsort[i];
        
        for(int j=0;j<adj[node].size();j++){
            int neighbour=adj[node][j].first;
            int weight=adj[node][j].second;
            int prevDist=dist[neighbour];
            int canBeNewDistance=dist[node]+weight;
            
            dist[neighbour]=min(prevDist,canBeNewDistance);//?imp
        }
    }
    
    //dist vector is of size V .Unreachabele nodes still have dist INT_MAx
    //so make their distance to -1
    for(int i=0;i<dist.size();i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
    
    return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends