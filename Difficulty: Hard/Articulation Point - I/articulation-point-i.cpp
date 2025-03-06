//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
  void Dfs(int node,int parent,vector<int>adj[], vector<int>&disc, vector<int>&low,vector<bool>&articulation,vector<bool>&visited,int&timer)
  {
      disc[node]=low[node]=timer;
      visited[node]=1;
      int child=0;
      
     
      for(int j=0;j<adj[node].size();j++){
          int neib=adj[node][j];
          
          if(parent==neib)
          continue;
          //neib already visited
          else if(visited[neib]){
              low[node]=min(low[node],disc[neib]);
              //?here we will take disc[neib] instead of low[neib] in min()
          }
          else{
              child++;//this is for root node (root node is a articulation pt if its has two or more child)
              timer++;
              Dfs(neib,node,adj,disc,low,articulation,visited,timer);
              
              //?checking of articulation pt for root(whose parent=-1) will not done here
              if(disc[node]<=low[neib] && parent!=-1){
                  articulation[node]=1; //articualtion poit find
              }
              
               low[node]=min(low[node],low[neib]);
              //?here we will take low[neib] instead of disc[neib] in min()
              
          }
      }
      
      //for rooot node (whose parent==-1) if it has more than 2 child than it is a articulation pt
      if(child>1 && parent==-1){
          articulation[node]=1;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
      
      vector<bool>articulation(V,0);
      vector<int>disc(V);//store time at which they discovered
      vector<int>low(V);
      vector<bool>visited(V,0);
      
      int timer=0;
      int node=0;
      int parent=-1;
      Dfs( node,parent,adj,disc,low,articulation,visited,timer);
      
      vector<int>ans;
      for(int i=0;i<V;i++){
          if(articulation[i]==1){
              ans.push_back(i);
          }
      }
      
      
      if(ans.size()==0){
          ans.push_back(-1);
      }
      
      return ans;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends