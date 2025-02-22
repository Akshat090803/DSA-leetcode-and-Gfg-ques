//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(int node, vector<int>adj[] , vector<bool>&visited){
     visited[node]=1;
     
     for(int j=0;j<adj[node].size();j++){
         
         if(!visited[adj[node][j]]){
             dfs(adj[node][j] , adj,visited);
         }
     }
 }
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    
	     //for euler circuit
	    //degree of all nodes should be even i.e, oddDegreeCount=0
	    //all nodes should be part of single component , (all non-zero degree nodes shoud be connected)
	    //neglect condition 2 for nodes who have degree 0
	    
	     //step1 degree count 
	    vector<int>deg(V,0);
	    int oddDegreeCount=0;
	    for(int i=0;i<V;i++){
	        deg[i]=adj[i].size();
	        //if degree is odd,
	        if(deg[i]%2)
	        oddDegreeCount++;
	        
	    }
	    
	    //for euler circuit , all nodes degree must be even i.e, oddCount=0
	     if(oddDegreeCount!=0) 
	    return 0;
	    
	    //else when oddcount==0 
	    //check nodes should be part of single component , (all non-zero degree nodes shoud be connected)
	    vector<bool>visited(V,0);
	    //start dfs/bfs from first non-zero degree Node , and check all non-zero degree nodes are visited 
	    //run dfs from only one node no need to apply dfs taking each node as src one by one as euler path is not asked ,only asked is euler path exist or not
	    for(int i=0;i<V;i++){
	        if(deg[i]){
	            dfs(i,adj,visited);
	            break; //see after apply dfs from first non-zero deg node we don't take other nodes as src , we break
	        }
	    }
	    
	    
	    //check if all non-zero nodes are visisted /all nodes should be part of single component
	    for(int i=0;i<V;i++){
	        if(deg[i] && !visited[i]) return 0; //neither euler path nor euler circuit exist as condition two not satisfield
	    }
	    
	    
	    return 1; //euelr circuit exist 
	    //i.,e when oddCount=0 and all non-zero degree nodes are visted (part of single component)
	    
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends