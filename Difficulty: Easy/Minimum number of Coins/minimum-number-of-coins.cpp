// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int>curr={2000,500,200,100,50,20,10,5,2,1};
        vector<int>coins;
        
        int i=0;
        while(N){
            if(curr[i]<=N){
                N=N-curr[i];
                coins.push_back(curr[i]);
            }
            else{
                i++;
            }
        }
        
        return coins;
    }
};