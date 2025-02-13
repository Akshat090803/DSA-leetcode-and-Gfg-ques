//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
        //!This is almost simlilar to  prerequisite task problem gfg
        //?only difference is that instead of true or false we have to return array
        //and in prerequite problem we were given a vector of pair as a input but here is vector vector 
        //so instead of .first and .second we will take [0] and [1] for first and second
        
        //?--------------------------------------------------
        //This is like topological sort
        //menas two complete task v you have to finish task u first
        //just like u->v you have to visit vertice u first than v (topological soty)
        //here pairs are given [1,0] here v is 1 u is 0 menas ,to complet task 1 you have to first compleet task 0
        //[2,1] v is 2 u is 1
        //so we will found topological sort and count vertices come in sort .
        //If vertices count == total vertices (we successfully found topological sort ) henace we can finishh all tasks so return true
        //if vertices count!= total vertices menas we can't complete all tasks return false
        //? when vertices count == total vertices means graph is directed Acyclic thats why we able to find topological sort
        //?count!= total means cycle is present in directed graph ,Thats why we can't find totpological sort
        //!In short , if cycle is present in given drected graph , we can't complete all tasks
        //!If cycle is not present in directed graph , we can solve all tasks
        //!and we know to detect cycle in directed graph we can use Kahn's algorihm 
        
        //create adjacency List from  the above prerequisites arrays
        vector<vector<int>> adj(N);
        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        //?in pair [1,0] v is 1 and u is 0 so it is [v,u]
        vector<int>inDegree(N,0);
        //calculate inDegree;
        for(int i=0;i<N;i++)
        for(auto x : adj[i]) inDegree[x]++;
        
        queue<int>q;
        //push all 0 indegree vertice in queue
        for(int i=0;i<N;i++) {
            if(inDegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            //check for neighbours
            for(int j=0;j<adj[node].size();j++){
                int vertex=adj[node][j];
                inDegree[vertex]--;
                if(inDegree[vertex]==0) q.push(vertex);
            }
        }
        
        
        return (ans.size()==N) ? ans : vector<int>();
        //return ans if size==total vertice else return empty array
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends