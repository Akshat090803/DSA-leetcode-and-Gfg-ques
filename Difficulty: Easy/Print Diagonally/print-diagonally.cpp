class Solution {

  public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A) {
                
                vector<int>ans;
                 int row=A.size();
                 int col=A[0].size();
                 
                //upper traingle 
                for(int i=0; i<row;i++){
                    int c=i;
                    for(int r=0;r<=i;r++){
                        int ele= A[r][c];
                        c--;
                        ans.push_back(ele);
                    }
                }
                
                //lower traingle
                for(int i=1;i<row;i++){
                    int c=col-1;
                    for(int r=i;r<row;r++){
                        int ele= A[r][c];
                        c--;
                        ans.push_back(ele);
                    }
                }
                
                return ans;
    }
};