//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
   bool dfsWay(int node,vector<vector<int>>& adj,vector<int>&color ){
       
      for(int j=0;j<adj[node].size();j++){
                        int vertex=adj[node][j];
                        //if color not assignes
                        if(color[vertex]==-1){
                            color[vertex] = (color[node]+1)%2;
                            //(color[node]+1)%2; this will do if node color is 0 than color of vertex will be (0+1)%2 =1 i.e, opposite color of node will assigned to neighbour similar if node color is 1 , 0 will be assigned to neigbour
                           //make recursive call
                           bool ret_val=dfsWay(vertex,adj,color);
                           if(ret_val==false) return false;
                           //don't check firther
                        }
                        else{//when color already assigned
                          if(color[vertex]==color[node]) return false;
                          //measn if adjacent node has same color ,return false as it indicate that two adjacent nodes are in same set/group
                            
                        }
                    }
                    return true;
   }
    bool isBipartite(vector<vector<int>>& adj) {
        //?There are two ways two solve problem Using Bfs and Using Dfs
        //!time and space for both way is same T-O(v+e) and space O(v)
        //it is like 2-coloring probblem (red and black)
        //?Using BFS 
        // make a color arr initialise with -1 indicating color not assigned to anyone yet
        //color will be either 0 or 1 
        //look at all its neighbour
        //if color is  not assigned 
        //--->assign a color to them. assign color Opposite of yourself
        //--->push neighbiur in queue
        
        //else when color is already assigned to neighbour
        //-->check if neighbour has same color as node , return false as it is not a bipartite graph than
        
        vector<int>color(adj.size(),-1);
        queue<int>q;
        
        for(int i=0;i<adj.size();i++){
            //this is done so that unconnected graph also gets visited
            if(color[i]==-1){
                q.push(i);
                color[i]=0; //we are taking default to color 0 .You can take 1 also
                
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    
                    //visiting neighbour (main logic)
                    for(int j=0;j<adj[node].size();j++){
                        int vertex=adj[node][j];
                        //if color not assignes
                        if(color[vertex]==-1){
                            color[vertex] = (color[node]+1)%2;
                            //(color[node]+1)%2; this will do if node color is 0 than color of vertex will be (0+1)%2 =1 i.e, opposite color of node will assigned to neighbour similar if node color is 1 , 0 will be assigned to neigbour
                            q.push(vertex);
                        }
                        else{//when color already assigned
                          if(color[vertex]==color[node]) return false;
                          //measn if adjacent node has same color ,return false as it indicate that two adjacent nodes are in same set/group
                            
                        }
                    }
                }
            }
        }
        return true;
        
        //!Dfs Way
        //?Same logic as BFS way
        //just use dfs instead of bfs rest logic for neigbouring nodes will be same
    
        // vector<int>color(adj.size(),-1);
        // for(int i=0;i<adj.size();i++){
        //     if(color[i]==-1){
        //         color[i]=0;//default color 0 we can take 1 also
        //          bool ret_val=dfsWay(i,adj,color);
        //          if(ret_val==false) return false;
        //     }
        // }
        // return true;
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
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends