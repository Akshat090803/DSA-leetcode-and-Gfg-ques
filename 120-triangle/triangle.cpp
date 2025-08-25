class Solution {
public:
   int minTotal(int row , int i , int n , vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if(row==n-1) return triangle[row][i];
    if(dp[row][i]!=-1) return dp[row][i];
    int min_=INT_MAX;
     //if i can go down to ith index of next row . //This will be always true , so dont put in if condition
      min_ = min(min_ , minTotal(row+1 , i , n , triangle , dp));

      //if I can go to i+1th index of next row
      //This condition will also be true every time as each time we move to next row , number of columns / ele in that row also increase by 1 . i.e, in row 0 ele 1 , in row 1 ele 2  , in row 2 ele 3 (Note we are following 0 based indexing for row if you see in 1 based index row 1 has 1 ele , row 2 has 2 ele)

    // ?  if(i+1 <= row+1){   //so this condition will also be true evry time 
          min_= min(min_ , minTotal(row+1 , i+1 , n , triangle,dp));
    //?   }

      return dp[row][i]=triangle[row][i] + min_;
   }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        //if we use normal recursion we get T.L.E Time - O( 2^N)

        //! If we do using Top Down Dp , we still getting TLE (TIme O(N^2))
        //  vector<vector<int>> dp(n);
        //  for (int r = 0; r < n; r++) dp[r].assign(r+1, -1);
        // return minTotal(0,0,n,triangle , dp);
//-------------------------------------------------------------
        //!Try with Bottom Up  with space optimization

        //Bottom Up with space optimization
        //we moving backward from n-2 to 0 as we know by this final ans will be at dp[0] . if we move forward form 0 to n-2 for final ans , we have to traverse whole last row to find min at that row and return that 
        //and also we can't be able to use space optimization 
        //we didnt start fiom n-1 and start form n-2 as at n-2 the value of last row will be thir min value .
    // vector<int> dp = triangle[n-1]; // start with last row

    // // bottom-up calculation
    // for (int row = n-2; row >= 0; row--) {
    //     for (int i = 0; i <= row; i++) {
    //         dp[i] = triangle[row][i] + min(dp[i], dp[i+1]);
    //     }
    // }
    // return dp[0];

    //-----------------------------
    
    //!Bottom up without space optimziation space O(N^2)
   
      
    // bottom-up calculation
        vector<vector<int>> dp(n);
        for (int r = 0; r < n; r++) dp[r].assign(r+1, INT_MAX);

        dp[0][0] = triangle[0][0]; //dp intializatiion

    for (int row = 0; row <n-1; row++) {
        for (int i = 0; i <= row; i++) {
           dp[row+1][i]= min(dp[row+1][i] , dp[row][i] + triangle[row+1][i]);
           dp[row+1][i+1]= min(dp[row+1][i+1] , dp[row][i] + triangle[row+1][i+1]);
        }
    }

    //if we move backward we dont have to do this step as final ans will be at dp[0][0]
    int min_=INT_MAX;
    for (auto x:dp[n-1]) min_=min(min_,x);
    return min_;
    
    }

};