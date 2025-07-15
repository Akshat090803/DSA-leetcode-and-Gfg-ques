class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char>st;

         int closeCount=0;

         for (char x:s){
            if(x=='('){
                st.push('(');
            }else{
                if(st.empty()){
                    closeCount++;
                }else{
                    st.pop();
                }
            }
         }

         return st.size()+closeCount;

    }
};