class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        //instead of constructing target array from arr having 1 1 1... initially
        //we will prcess in backward direction i.e, from target arr and see whether we can get arr having 1 1 1 1 1..
    //the max ele will be the x (the sum of all elements currently in your array.)
    //remainng sum = sum - maxEle
    //ELE= MaxEle % remainnf sum
    //!As we will need maxzele at each iteration we will use MAxHeap
   //?we will run while loop until MaxHeap top is not equal to 1 as when top is 1 it means all ele in maxHeap is 1 i.em arr=1,1,1..... starting point as per ques
    priority_queue<int>pq(target.begin(),target.end()); //MAxHeap
     
     long long remainSum=0;
     long long sum=0;
     for(auto x:target) sum+=x;
    
     while(pq.top()!=1){
        
         long long maxEle=pq.top();
         pq.pop();
         remainSum=sum-maxEle;
         if(remainSum<=0 || remainSum>maxEle) return 0;

    //   long long Element=maxEle-remainSum;
    //this will give tle for  target=[10000000, 1] etc.
    
    // The % prevents the TLE from the case (e.g., target=[10000000, 1]) where the largest element is significantly bigger than the sum of other elements.
         long long Element=maxEle%remainSum;
         if(Element==0){
            if(remainSum==1) return true;
            else return false;
         }

        // sum=maxEle ; //we are moving backward;
         //so inprevious iteration(if we see backwardly sum will be maxEle that;s why in current iteration , it is maxEle)
         //?or we can right this as
         sum=remainSum+Element;
         pq.push(Element);
       
     }

     return 1;
     
    }
};