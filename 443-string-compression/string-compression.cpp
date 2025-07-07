class Solution {
public:
    int compress(vector<char>& chars) {
        int start=0;
        int end=1;
        int count=1;

        int n=chars.size();
        if(n==1) return 1;

        while(end<n){
            if(chars[end]==chars[start]){
                count++;
            }
            else{
                if(count==1){
                    start++;
                    chars[start]=chars[end];
                }else{
                    start++;
                    string countStr=to_string(count);
                    for (char x : countStr){
                        chars[start]=x;
                        start++;
                    }

                    chars[start]=chars[end];
                    count=1;
                }
            }
            end++;
        }

        if(count!=1){
            start++;
                    string countStr=to_string(count);
                    for (char x : countStr){
                        chars[start]=x;
                        start++;
                    }
return start;
                  
        }
        return start+1;
    }
};