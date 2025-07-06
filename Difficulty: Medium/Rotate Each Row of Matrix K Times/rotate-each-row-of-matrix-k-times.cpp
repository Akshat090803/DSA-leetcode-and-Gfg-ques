// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        //!time - O(m*n)
        //!space - O(1)
        int row=mat.size();
        int col=mat[0].size();
        k=k%col;
        
        for(int i=0;i<row;i++){
             
             reverse(mat[i].begin(), mat[i].end());
             reverse(mat[i].begin(),mat[i].end()-k);
             reverse(mat[i].end()-k,mat[i].end());
        }
        
        return mat;
    }
};