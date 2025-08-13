class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        

        vector<int>ans;
        vector<vector<int>>v(tasks.size());

        for(int i=0;i<tasks.size();i++){
               int arr=tasks[i][0];
               int prr=tasks[i][1];
               v[i].push_back(arr);
               v[i].push_back(i);
               v[i].push_back(prr);
        }


        sort(v.begin(),v.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        long long timer=0;

        int i=0;
        while(i<tasks.size()){

            while(i<tasks.size() && v[i][0] <= timer ){
                pq.push({v[i][2],v[i][1]});
                i++;
            }

            if(!pq.empty()){
                auto tp=pq.top();
                pq.pop();
                timer+=tp.first;
                ans.push_back(tp.second);
            }else{
                timer=v[i][0];
            }
        }

    while(!pq.empty()){
         auto tp=pq.top();
                pq.pop();
                timer+=tp.first;
                ans.push_back(tp.second);
    }
        return ans;


    }
};