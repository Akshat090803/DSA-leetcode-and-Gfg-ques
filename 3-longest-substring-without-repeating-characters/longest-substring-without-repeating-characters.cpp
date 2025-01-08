class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<bool>occurrence(256,0);
//here we used sliding window method 
//we keep inceeasing second and if repeative char is found we increase first to that repeating char while making occ of all char 0 till first not reached that repated char
//than make than make occur 1 and compare len than scond++
       int first=0;
       int second=0;
       int len=0;
       int n=s.size();
       while(second<n){
              if(occurrence[s[second]]==1){ //this checks char previously occured or not
                while(occurrence[s[second]]){ //jb tk we not reached the first occ of that char we keep makinf all char 0 means reducing size of the window
                    occurrence[s[first]]=0;
                    first++;
                }
              }
//then we will look for new substr
               occurrence[s[second]]=1;//so make that char occcur=1 as that char will be now part of new substr
                len=max(len,(second-first+1)); //compare len with previus substr len
                second++;
       }
       return len;
    }
};