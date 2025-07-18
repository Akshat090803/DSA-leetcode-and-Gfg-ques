class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
         if(tickets[k]==1) return k+1;

         int minTime=tickets[k];
         int totalTime=0;
         for(int i=0;i<=k;i++){
            totalTime+=min(minTime,tickets[i]);
         }
      
      //this becuase if tickets at k all purchased than why to include time of people behind k;
         for(int i=k+1;i<tickets.size();i++){
            totalTime+=min(minTime-1,tickets[i]);
         }

         return totalTime;
    }
};