//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
       visited[node]=1;
       
       for(int j=0;j<adj[node].size();j++){
           int vertex=adj[node][j];
           if(!visited[vertex]){
               dfs(vertex,adj,visited);
           }
       }
   }
    int isCircle(vector<string> &arr) {
        // ["abc", "bcd", "dfa"]
        //we have work form first and last char of each string,b//w char no use
        //[ac , bd , da]
        //in ac (abc) tells that after abc we have to visit string starting form c
        //in bd(bcd) tells after bcd ,we have to visit  string starting from d
        //in da (dfa) tells after dfa we have to vsiit string starting from a
        //so i f we see ac , bd , da
        //we draw a relation
        //ac , bd ,da menas
        //a->c
        //b->d
        //d->a
        
        //if we find euler circuit in this realtion , than circle of string exist
        
        //as directed graph will form
        //so for directed graph ,for euler circuitwe check indegree==outdegree
        
        vector<vector<int>>adj(26);
        vector<int>inDeg(26,0);
        vector<int>outDeg(26,0); 
        //insetad of node as a,b,c we take them as 0,1,2 i.e, a menas 0 , b means 1  , z menas 25
        
        //?we will calculate indeg and outdegree simulatneously will creating adjacency list
        for(int i=0;i<arr.size();i++){
            string temp=arr[i];
            int u= temp[0]-'a';
            int v=temp[temp.size()-1]-'a';
            // in abdc, we need first amd last char abdc=>ac and ac menas a->c ie., so temp[0] will be u and temp[last]=v
            adj[u].push_back(v);
            inDeg[v]++; //u->v ,edge incoming on v , so v indeg ++
            outDeg[u]++; //u->v , edge outgoing form u , so u outDeg ++
        }
        
        //for euler circuit to exist , oddCount must be 0
        //for directed graph, menas there should not be any node with inDeg!=outDeg as it menas oddCount++;
        //so if any node found with inDeg!=outDeg return 0 as euler circuit can't form
        for(int i=0;i<26;i++){
            if(inDeg[i]!=outDeg[i])
            return 0;
        }
        
        //now as all node have eqaul inDeg and outDeg
        //we check if they are a single component or not
        //apply dfs or bfs
        //we use dfs 
        vector<bool>visited(26,0);
        int node=arr[0][0]-'a';
        //we can take any vertice with its degree not equal to 0 as  node/src node for dfs
        //we take arr[0][0] , first char of first string as its degree will not be 0
        
        dfs(node,adj,visited);
        
        for(int i=0;i<26;i++){
            if( inDeg[i] && !visited[i]){
                return 0;
                //we can take outDeg[i] also instead of inDg[i] in if conditon
                //for any node whose degree exist and it is not visited menas it is not a part of single compinent so return 0 as this is also a condition required for eulelr circuit that all node must be aprt of single component
            }
        }
        
        return 1; //all condition for euler circuit satisfied so return 1
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends