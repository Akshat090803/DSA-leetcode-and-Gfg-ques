class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());

        while(pq.size()>1){
            int y= pq.top(); //first largeste
            pq.pop();
            int x=pq.top(); //second largest i.e, x<=y
             pq.pop();
            if(y-x){ //this will handle all case if y==x than y-x=0 so condition false , nothing will push , and we know y>=x so y-x always +ve
                pq.push(y-x);
            }
        }

        if(pq.empty()) return 0;

        return pq.top();
    }
};