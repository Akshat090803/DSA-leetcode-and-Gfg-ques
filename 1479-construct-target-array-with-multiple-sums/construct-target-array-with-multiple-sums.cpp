class Solution {
public:
    bool isPossible(vector<int>& target) {
        //if we start form [1,1,1,...] , it will be very difficult to judge at which position sum should place so that we can reach target array.
        ///so we use reverse approach , we start from target array , and try check if we can reach [1,1,1....]

        //we use max heap , the highest value will be the recent value in which sum was added and pop it.
        //to get actual value of Max ele , we subtract rest ele sum form the MaxELe as as actualValue + Rest values sum = MaxEle;
        //if actaul value ==1 dont push again else push it again as it needs to redue further 
        //for next iteration , sum will be Sum - newMaxTop + Actaul VAlue
        //?why?  suppsoe [9,3,5] 
        // 
        priority_queue<int>pq(target.begin(),target.end());
        long long sum=0;
        for(int x:target) sum+=x;
        sum-=pq.top();
        while(pq.top()!=1 && !pq.empty()){
            if(sum <=0 || sum>pq.top()) return false; //consider [1,1,1,2]
            // int actualValue=pq.top() - sum;
            int actualValue=pq.top() % sum; //to avaoid overflow [1,10000000] , we use % instead of -
            pq.pop();
            if(actualValue > 1) pq.push(actualValue);
            else if (actualValue==0){ //suppse pq.top() was 2 and sum=1 sp pq.top()%1 i.em 2%1 = 0 , as we are using % , if we used - ,than 2-1 =1 which was required, so if actaulValue 0 and sum is 1  , return true
                if(sum==1) return true;
                else return false;
            }

            sum-=pq.top();
            sum+=actualValue;
        }
        return true;
    }
};