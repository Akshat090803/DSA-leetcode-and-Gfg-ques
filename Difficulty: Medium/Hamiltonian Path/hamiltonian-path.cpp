//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    bool Dfs(int node,int &count,int N,vector<vector<int>>&adj,vector<bool>&visited){
        
        visited[node]=1;//mark node visited
        count++; //increase count by 1 which tells out of N vertices count vertices visited
        //we use this so that if count==N return true;
        if(count==N)
        return true; //hamilton path found
        
        //visit neighbours
        for(int j=0;j<adj[node].size();j++){
            int neib=adj[node][j];
            bool return_val=false;
            if(!visited[neib]){
                return_val=Dfs(neib,count,N,adj,visited);
            }
            
            if(return_val)
            return true;
            //if dfs returns true, menas hamilton path found do don't go for further for other neighbours and return true from here 
        }
        
        visited[node]=false; //for backtracking mark unvisited
        count--;//reduce count also
        return false; //hamilaton found not found
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // 
        //vertices start from 1 i.e, 1 ≤ Edges[i][0],Edges[i][1] ≤ N
        //so we either use 1 based indexing in adj or while pushing verties in adj reduce them by 1
        
        vector<vector<int>>adj(N+1);
        for(auto x:Edges){
            int u=x[0];
            int v=x[1];
            //as it is a undirected graph 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(N+1,0);
        
        //We will make Dfs call N times taking each node as a src one by one to check hamilton path exist or not
        //ad if any src i dfs call returns true, we returns true as a ans
        for(int i=1;i<=N;i++){
            int count=0;
            int src=i;
            bool return_val=Dfs(src,count,N,adj,visited);
            
            if(return_val)
            return true;
        }
        
        
        return false;
        
    }
};
 


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends