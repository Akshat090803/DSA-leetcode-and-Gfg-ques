class Solution {
public:
    string reverseWords(string s) {
         stack<string>st;
         string str;
         for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else{
                if(str.size()) st.push(str); 
                str="";
            }
         }

          if(str.size()) st.push(str); 


         s="";
         while(st.size()>1){
            s+=st.top();
            st.pop();
            s+=' ';
         }
         s+=st.top();
         return s;
    }
};