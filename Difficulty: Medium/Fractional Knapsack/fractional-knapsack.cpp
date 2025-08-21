// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,int>>v;
        for(int i=0;i<wt.size();i++){
            double val_wt = (double)val[i] / (double)wt[i];
            v.push_back({val_wt,wt[i]});
        }
        
        sort(v.begin(),v.end(),greater<pair<double,int>> ());
        
        double ans=0;
        
        for(int i=0;i<v.size();i++){
            
            double fract = min(v[i].second,capacity);
            capacity-=fract;
            fract*=v[i].first;
            
            ans+=fract;
            
            if(capacity==0) break;
        }
        
        return ans;
    }
};
