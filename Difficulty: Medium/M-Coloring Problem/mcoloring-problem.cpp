//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  //non-dfs apporach /Here we are not making recursive call for all adjacent nodes.We are making recursive call for just next node i.e, for  node+1
    bool assignColor(int node, vector<vector<int>>&adj,vector<int>&colorInfo,int v,int m){
        
        //base condition
        if(node==v){ //menas  color is assigned to all nodes so return true
            return true;
        }
        
        
        //check for all colors 
       
        for(int i=0;i<m;i++){
            
             bool isPossible=true;
             
            //check if we can assign color i to node by checking adjacent node that they don't have that color
            for(int j=0;j<adj[node].size();j++){
                int neib=adj[node][j];
                if(colorInfo[neib]==i){
                    //when neib has same color ,we can 't assign that color to node'
                    //so mark isPossible false;
                    isPossible=false;
                    break;
                }
            }
            
            //if it is possible to assign color i to node ,assign color and make  next call
            if(isPossible){
                colorInfo[node]=i; //assign color
                bool ret_val=assignColor(node+1,adj,colorInfo,v,m); //make call for just next node i.e, node+1 and not for all adj node
                
                if(ret_val){ //when func return tru menas we succesfully assign color so return true
                    return true;
                }
                
                colorInfo[node]=-1;//when func return false menas we didn't successfully assign color.
                //so again make color =-1 so that we can reassign different color
            }
        }
        
        
        return false; //if we are not able to assign any color return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        
        //we use permutaion logic
        //make combination each color and if permuation is correct(all nodes get color) return1
         
         //first create a adjacency list;
         vector<vector<int>>adj(v);
         for(auto x:edges){
             int u=x.first;
             int v=x.second;
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         
         vector<int>colorInfo(v,-1);//initially no color assigned to vertices
         
         for(int i=0;i<v;i++){
             
             if( colorInfo[i]==-1){
                 bool ret_val=assignColor(i,adj,colorInfo,v,m);
                 if(ret_val==false)
                 return false; //menas can't assign color
             }
         }
         
         return true; //successfully assigned the color
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends