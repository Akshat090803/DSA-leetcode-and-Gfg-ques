//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        //!Way-1  
        //code is similar but here it is given for no path than value is -1 instead of INT_MAx\
        //so -1 will create problem in choosing minmum ,so we convert -1 to INT_MAnx than apply logic
        
        int n=mat.size();
        //converting -1 to INT_MAX
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1)
            mat[i][j]=INT_MAX;
        }
        
        //floyd warshall algo
        //this k loop is for intermediate node
        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)//for traversing all values adn findind min disance using intermediate node
        for(int j=0;j<n;j++){
            
            if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX)
            continue;
            
            //thsi if condition will prevent from int overflow
            //suppose either mat[i][k] or mat[j][k] is INT_MAX than in mat[i][j]=min(mat[i][j] , mat[i][k]+mat[j][k]),, mat[i][k]+mat[j][k] will casue int overflow
            
            //reason two 
            //mat[i][k]==INT_MAX or mat[k][j]==INT_MAX indicates that there is now path b.w i to k for k to j
            //if there is no path b/w i to k than we can't reach j via k to j as we will never reach k similarly if mat[k][j]=INT_MAX we can reach i to k but not k to j hence we can't reach i to j via k
            
            //reason 3 this will handle case of negative weights also (just like in nellman ford)
            
            //realax edge
            mat[i][j]=min(mat[i][j] , mat[i][k]+mat[k][j]);
            //mat[i][k]+mat[k][j] means i to k + k to j  i,e (i to j transivity property)
            
        }
        
        //as we converted -1 to INT_MAX 
        //again ocnvert INT_MAX to -1 as in ques for no path exist it value is -1
         //converting -1 to INT_MAX
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(mat[i][j]==INT_MAX)
            mat[i][j]=-1;
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends