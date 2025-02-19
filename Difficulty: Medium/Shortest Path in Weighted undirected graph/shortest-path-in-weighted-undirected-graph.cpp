//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //as it is not given that graph is directed acyclic , we can't use topological sort method 
        
        //we use dijkstra method
        //and for storing the nodes of shortes path we use parnt vector
        
        //create adjacency list
        vector<vector<pair<int,int>>>adj(n+1); 
        //?as nodes are given form 1 to n so we are using 1 based indexing 
        //we can do this using zero based indexing also
        
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            //as graph is undirected
        }
        
        
        //dijkstra logic
        vector<int>dist(n+1,INT_MAX); //size n+1 beacuse 1 based indexing
        vector<bool>explored(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>parent(n+1,-1);//parent vector store the parent of curr node
        
        //preprocessing
        dist[1]=0; //as given src will be 1 always and distance form src to src is 0
        pq.push({0,1});
        parent[1]=-1; //for source there will be no parent
        
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            
            //node already explored means its distance is confirmed
            if(explored[node])
            continue;
            
            //else mark exoplored
            explored[node]=1;
            
            //visit neighbours
            for(int j=0;j<adj[node].size();j++){
                int neighbour=adj[node][j].first;
                int weight=adj[node][j].second;
                
                int prevDistance=dist[neighbour];
                int canBeNewDistance=dist[node]+weight;
                if(!explored[neighbour] && canBeNewDistance < prevDistance ){
                    dist[neighbour]=canBeNewDistance;
                    pq.push({dist[neighbour] , neighbour});
                    parent[neighbour]=node; //extra step added in dijkstra alg so that we can know about parent
                }
            }
            
            
        }
        
        vector<int>path;
        //means we cant reach n form 1
        if(parent[n]==-1){
            path.push_back(-1);
            return path;
        }
        
        int dest=n;
        while(dest!=-1){
            path.push_back(dest);
            dest=parent[dest];
        }
        
        path.push_back(dist[n]);  //push the distanceto traeach the n from 1
        reverse(path.begin(),path.end());
        
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends