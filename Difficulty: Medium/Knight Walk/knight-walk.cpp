//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int row[8]={2,2,-2,-2,1,-1,1,-1};
int col[8]={1,-1,1,-1,2,2,-2,-2};

bool valid(int i,int j ,int n){
    return i>=0 && i<n && j>=0 && j<n;
}

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // a knight can walk in 8 direction
	    //top-top-left , top-top-right , bottom-bottom-left,bottom-bottom-right,left-left-top,left-left-right,right-right-top,right-right-bottom
	    //So vertices in that 8 direction will be the neighbour of node
	    //we can think chessboard as adjacency matrix
	    ///initiallly chessbord will be initilaised to 0 and src as 1 menas no one is visited except src
	    //As There is no weight is given  ,menas each step is of 1 weight ,so we apply bfs
	    //each level will be a distance 1  from src
	    //i,em level-1 ele will be at distanve 1 from src
	    //level 2 elel will be at distance two from src (level1-level2 distance is 1)
	    
	    //when src and target same
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;
	    
	    //!As in ques 1-based indexing is given
	    //so we reduce target's pos (row ,col) and sources pos (row,col) by 1 so to bring them in 0-based indexing as we written code on basis of 0-based index
	    //i,e, i=1,j=1 become i=0,j=0
	    
	    //if we write code on basis of 1-based index than we have to create chessbord of size N+1 
	    //and in valid function instead of  i>=0 && i<n && j>=0 && j<n; we have yo do like this  i>=1 && i<=n && j>=1 && j<=n;
	    
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    vector<vector<int>>chessB(N,vector<int>(N,0));//initialise with 0 means unvisited
	    
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});//push src i,j in queue
	    chessB[KnightPos[0]][KnightPos[1]]=1; //mark src as visted
	    int step=0;
	    
	    while(!q.empty()){
	        int count=q.size();
	        
	        while(count--){
	            int i=q.front().first;
	            int j=q.front().second;
	            q.pop();
	            
	            //neighburs (Total 8 neighbours can be)
	            for(int k=0;k<8;k++){
	                int new_i=i+row[k];
	                int new_j=j+col[k];
	                
	                if(valid(new_i,new_j,N) && chessB[new_i][new_j]==0){
	                 
	                 if(new_i==TargetPos[0] && new_j==TargetPos[1]) return step+1; //we reached the target   
	                 //else
	                 chessB[new_i][new_j]=1; //mark visited
	                 q.push({new_i,new_j}); //push neighbour in queue
	                }
	            }
	        }
	        step++; //increase step after visiting all ele in curr level
	    }
	    
	    
	    return -1; //if we can't reach target from source
	    
	    
	 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends