class Solution {
  public:
    
    int result(int i ,  int W , vector<int> &val, vector<int> &wt,  vector<vector<int>>&dp){
         
         if(W==0 || i==val.size()) return 0;
         
        //  if(dp[i].count(currSum)) return dp[i][currSum];
         if(dp[i][W]!=-1) return dp[i][W];
         
         
         int include=0;
         int exclude=0;
         
         //include 
         //include only when bag has capacity to store
         if(W >= wt[i]){
            include =  val[i]+ result(i+1  , W - wt[i] , val , wt , dp);
         }
         
         //exclude
          exclude =   result(i+1 , W  , val , wt , dp);
          
          return dp[i][W] = max(include , exclude);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        // vector<vector<int>> dp(val.size()+1, vector<int>(W+1, -1));
        // return result(0,W,val,wt , dp);
        
        //Bottom UP
        vector<vector<int>> dp(val.size()+1, vector<int>(W+1, 0));
        
        //base case
        for(int firstWt=wt[0];firstWt<=W ; firstWt++){
            dp[0][firstWt]=val[0];
            //
        }
        
        for(int i=1;i<val.size();i++){
            for(int currWt=0;currWt<=W;currWt++){
                
                //exclude  = noValue + value when at prev row  
                int exclude = 0 + dp[i-1][currWt]; //dp[i-1][currWt-0 (0 beacause we are not including wt[i])]
                
                //include
                int include=0;
                if(wt[i] <= currWt){
                    include = val[i] + dp[i-1][currWt - wt[i] ];
                }
                
                dp[i][currWt]=max(include,exclude);
            }
        }
        
        return dp[val.size()-1][W];
        
    }
};