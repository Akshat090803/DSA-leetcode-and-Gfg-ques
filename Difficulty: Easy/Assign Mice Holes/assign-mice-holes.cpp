class Solution {
  public:
    int assignMiceHoles(int N, int M[], int H[]) {
        // code here
        sort(M,M+N);
        sort(H,H+N);
        
        int max_=INT_MIN;
        
        for(int i=0;i<N;i++){
            int time=abs(M[i]-H[i]);
            max_=max(max_,time);
        }
        return max_;
    }
};