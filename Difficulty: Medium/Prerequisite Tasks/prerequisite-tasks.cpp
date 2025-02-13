//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        
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
            adj[x.second].push_back(x.first);
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
        
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            
            //check for neighbours
            for(int j=0;j<adj[node].size();j++){
                int vertex=adj[node][j];
                inDegree[vertex]--;
                if(inDegree[vertex]==0) q.push(vertex);
            }
        }
        
        return count==N ? true : false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends