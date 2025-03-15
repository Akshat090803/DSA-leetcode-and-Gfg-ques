class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26,0); //A to Z
        int maxCount=0;

        for(auto x:tasks){
               freq[x-'A']++;
               maxCount=max(maxCount,freq[x-'A']);
        }

        int ans=(maxCount-1)*(n+1);

        //?now do +1 for how many char have their freq==maxCount;
        //as for AAABBB for n=2
        //this ans=(maxCount-1)*(n+1); will give 
        //A _ _ B _ _   (ans=6)
        // this  do +1 for how many char have their freq==maxCount; 
        //so A ans B have freq ==maxCount so increase ans by 2
        //ans+=2 (for A and B)
        //as now A _ _ B _ _ A B (ans=8)

        for(auto x: freq){
            if(x==maxCount)
            ans++;
        }

        //?the minimum cpu intervals will be equal to max(ans,tasks.size());
       //su[pos AAA BBB E (n=2)
       //tasks.size()=3+3+1=9
       //ans acc to our formula = (3-1)*(2+1) = 6
       //?ans+=2 ==> 8 (2 char have freq ==maxCount)
       //By formula space for E not included
       //acc to formula we are taking exactly n(2) gap b/w char as min gap required is 2.But gap can be greater than 2 also
       //so if ans is less Than tasks.size() return task.size() else ans
        
        ans=max(ans,int(tasks.size()));
       return ans;




    }
};