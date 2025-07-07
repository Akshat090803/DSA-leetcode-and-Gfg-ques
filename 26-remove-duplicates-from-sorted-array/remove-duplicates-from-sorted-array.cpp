class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       int write=0;
      int read=0;

      int n= arr.size();
      while(read<n){
        int currNum= arr[read]; 
       
        //go to next unique number
        while( read<n){
            if(arr[read]!=currNum){
              break;
            }

            read++;
        }

        arr[write]=currNum;
        write++;

      }
      return write;  // write will give the count  
    }
};