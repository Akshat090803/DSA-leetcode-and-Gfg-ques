class Solution {
  public:
    string countAndSay(int n) {
        // code here
           string ans="1"; //this is th pattern at n=1
         string say;
        
         
       //if n=1 loop will not run and we directly return ans ie. "1"
        for(int i=2;i<=n;i++){
           
           int read=0;
           int count=0;
           say="";
          
        //   do run len coding for i=1 to i< n times
        //and change ans by a in every for loop iteration
           while(read<ans.size()){
               count=0;
               char ch=ans[read];
               while(read<ans.size() && ans[read]==ch){
                   count++;
                   read++;
               }
               
               say+=to_string(count);
               say+=ch;
               
           }
           ans=say;
        }
        
        return ans;
    }
};