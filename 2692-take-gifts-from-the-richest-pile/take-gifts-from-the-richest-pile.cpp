class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        //as we required frequent acces to max value
      //and we will do insertion and deletion both, so we will use MaxHeap

      priority_queue<int>pq;
      long long totalGifts=0;
      for(int x:gifts){
        pq.push(x);
        totalGifts+=x;
      }

      while(k--){
        long long maxGifts=pq.top();
        pq.pop();
        totalGifts-=maxGifts;
//Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
        maxGifts=sqrt(maxGifts);
        totalGifts+=maxGifts; //as originalno . of gifts were removed in above step Now add sqrt of original gifts as they are available 
        pq.push(maxGifts);
      }
      
      //we can do like this also. Instead of maintainng totalGifts variable we can run at last a seperate loop that iterates through heap and sums all value in heap as they will be the number of gifts remaining after k seconds.
      return totalGifts;

    }
};