class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        //as we required frquent access to max value
        //and we will do insertion and deletion both, so we will use MaxHeap
        priority_queue<int>pq; //MaxHeap
        for(int x:stones) pq.push(x);

        while(pq.size()>=2){
            int top_stone=pq.top();
            pq.pop();
            int blastResult= top_stone - pq.top(); //top stone - second top stone
            pq.pop();

            if(blastResult) pq.push(blastResult);//don't push when blastResult=0
        }

        return (pq.size()) ? pq.top() : 0;
        // At the end of the game, there is at most one stone left.
        // Return the weight of the last remaining stone. If there are no stones left, return 0.
    }
};