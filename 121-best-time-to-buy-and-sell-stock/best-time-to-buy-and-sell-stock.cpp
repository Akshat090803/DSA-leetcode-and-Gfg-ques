class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       int max_profit=0;

       int best_buy=prices[0];

       for(int i=1;i<n;i++){
        if(prices[i]>best_buy){
            max_profit=max(max_profit,prices[i]-best_buy);
        }else{
            best_buy=prices[i];
        }

       }
       return max_profit;
    }
};