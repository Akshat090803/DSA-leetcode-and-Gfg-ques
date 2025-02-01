class Solution {
public:
    string minWindow(string s, string t) {
        
        //Sliding window using
        //use map also for keep count of occurrence
        //variable "need" which tells all char included or not
        //ans_len (for storing the lentgth ) and ans_start for the start index of ans string
        //store the need of char of string t in map which tells which char need how many time
        //increase the window untill need not eqaul to 0
        //decreease need-- if  mp[x] is greater than 0 (during window increasing) menas  the required char is found so reduce the need

        //increase the need++ is mp[x] > 0 (during window reducing) means reuired char is removed from the window so need++ (menas it need to be again included)

        unordered_map<char,int>mp; //(char , requirement)

        for(auto x: t) mp[x]++; //(for eg t is ABC so map will be {A:1 ,B:1 , C:1}) menas A,B C all requirement is of 1 -1 charcter

        int start=0,end=0;
        int need=t.size();//how many char needed .Initially all char of t is needed
        int ans_length=INT_MAX;
        int ans_string_start_ind=-1;

        while(end<s.size()){

            if(mp[s[end]]>0) { //mp[x] will be greater than 0 only for the char of string T :reason see for loop (on line 17)
                need--;
            }
            mp[s[end]]--;

            while(need==0 && start<=end){
                if((end-start+1) < ans_length){
                    ans_length=(end-start+1);//update len
                    ans_string_start_ind=start; //update ans string start index also
                }
                mp[s[start]]++;//as letter will be removed form window increase it requirement

                if(mp[s[start]]>0) need++;
                //if after removing ,it requiremnt is greater than 0 (means) it's need to be included again so need++
                start++;//for reducing the window
                
            }
            end++;
        }

//constricting the ans string
     // If we found a valid window, return the substring
    if (ans_length == INT_MAX) {
        return ""; // No valid window found
    }
    
    return s.substr(ans_string_start_ind, ans_length); // Return the minimum window substring

    }
};