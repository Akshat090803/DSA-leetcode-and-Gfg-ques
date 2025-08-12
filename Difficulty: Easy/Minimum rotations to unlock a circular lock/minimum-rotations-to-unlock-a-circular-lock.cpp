// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        int ans=0;
        
        while(R){
            int r=R%10;
            int d=D%10;
            R=R/10;
            D=D/10;
            
            
            int clock=abs(d-r);
            // int anti=9-(d-r)+1;
            int anti=9-clock+1;
            ans+=min(anti,clock);
            
        }
        return ans;
    }
};