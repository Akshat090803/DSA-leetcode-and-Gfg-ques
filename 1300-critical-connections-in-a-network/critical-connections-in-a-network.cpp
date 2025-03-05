class Solution {
public:
   void Dfs(int node , int parent , vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,vector<bool>&visited,vector<vector<int>>&bridges,int&count) {
        
        disc[node] = low[node] = count;
        visited[node]=1; //mark node visited

        //neighbours
        for(int j=0;j<adj[node].size();j++){
            int neib=adj[node][j];

           //if parent and neigb same continue 
            if(parent==neib)
            continue;
            //else if neigb already visited
            else if(visited[neib]){
               low[node]=min(low[node],low[neib]);//just update low of node
            }
            //neighbour not visited
            else{
               count++;
               //make a recursive call
               Dfs(neib,node,adj,disc,low,visited,bridges,count);
                
                 low[node]=min(low[node],low[neib]);//update low of node
               //after returninf from call check between node and neighbour there is a bridge
               if(disc[node] < low[neib]){
                vector<int>temp;
                temp.push_back(node); //u
                temp.push_back(neib); //v
                bridges.push_back(temp); //menas in bridges we pushed {node,neib};
               }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<vector<int>> adj(n); // create adjList
        for (auto x : connections) {
            int u = x[0];
            int v = x[1];
            // as graph is undirected u->v will also v->u
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // things required
        vector<vector<int>> bridges; // this will return as ans
        vector<bool> visited(n, 0);  // track node visited or not

        vector<int> disc(n); // discovery vector , will tell about location of
                             // node i.e, for node 2 its location or value in
                             // disc will be 2 simialry for 3 value is 3 etc;

        vector<int> low(n); // will tell we can go form neighour to  node or
                            // vertice befor node from neighbour
        // it will be initilaized with node value than will update later in code
        // i.em it has initlally smae value as disc i,e for node 2 value of low
        // is 2 i.e, mtlb abhi wo apne aap se apne aap pr to ja skta he aur agr
        // node ya node se phle wali vertice pe ja skta he to wo code me update
        // ho jayega

        //?initializing disc and low vector
        // for (int i = 0; i < n; i++) {
        //     disc[i] = low[i] = i;
        // }

        // making dfs call
        int count=0;
        int node = 0;    // initial node 0
        int parent = -1; // as 0 is src/first node it has no parent so -1
        Dfs(node, parent, adj, disc, low, visited, bridges,count);

        return bridges;
    }
};