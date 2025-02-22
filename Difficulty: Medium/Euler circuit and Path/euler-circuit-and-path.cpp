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
	int isEulerCircuit(int V, vector<int>adj[]){
	    //for euler circuit
	    //degree of all nodes should be even i.e, oddDegreeCount=0
	    //all nodes should be part of single component , (all non-zero degree nodes shoud be connected)
	    //neglect condition 2 for nodes who have degree 0
	    
	    
	    //for euler path
	     //degree of all nodes should be even i.e, oddDegreeCount=0 or oddDegreeCount nodes should be exactly 2
	    //all nodes should be part of single component , (all non-zero degree nodes shoud be connected)
	    //neglect condition 2 for nodes who have degree 0
	    
	    //if Euler circuit exist than euler path will also exist return 2
	    //but vice versa not true as in euelr path odd count can be 2 also (return 1)
	    
	    
	    //step1 degree count is common to both 
	    vector<int>deg(V,0);
	    int oddDegreeCount=0;
	    for(int i=0;i<V;i++){
	        deg[i]=adj[i].size();
	        //if degree is odd,
	        if(deg[i]%2)
	        oddDegreeCount++;
	        
	    }
	    
	    
	    //we know for euler circuit ,oddCount==0 and for euler path to exist oddCount=0 or oddcount==2
	    //so if oddcount not eqaual to 0 and  2 return 0 (menas both not exist)
	    if(oddDegreeCount!=0 && oddDegreeCount!=2) 
	    return 0;
	    
	    //else when oddcount==0 or oddcount ==2
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
	    
	    
	    if(oddDegreeCount==0){
	        return 2; 
	        //oddCount 0 , means all degree are even 
	        //hence euler circuit exist
	        // and if Euler circuit exist than euler path will also exist 
	        //hence return 2
	    }
	    else{
	        return 1;
	        //menas oddCount==2 so only euler path exist  as for euler circuit oddCount=0
	    }
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends