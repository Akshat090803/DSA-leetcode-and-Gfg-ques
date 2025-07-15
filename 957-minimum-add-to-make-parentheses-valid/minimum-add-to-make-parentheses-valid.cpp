class Solution {
public:
    int minAddToMakeValid(string s) {
       

         int closeCount=0;
         int openCount=0;
         int oth=0;

         for (char x:s){
            if(x=='('){
                openCount++;
            }else{
               if(openCount>closeCount) openCount--;
               else if(openCount==0) oth++;
               else closeCount++;
            }
         }

         return openCount+closeCount+oth;

    }
};