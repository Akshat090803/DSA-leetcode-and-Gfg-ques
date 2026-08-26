class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
          
          //atleast one student will get minimum pages = max from arr as a assignment as
        //   asthe will be the smallest possible maximum.
        //so start = max of Arr
        // end = sum of pages of all books ( as it will be the upperbound)
        
        long start = *max_element(arr.begin(),arr.end());
        long end =0;
        
        for(int x:arr) end+=x;
        
        
      long ans =-1;
      
      int n = arr.size();
      if(k>n) return ans;
      
      while(start<=end){
          long limit = start + (end-start)/2;
         
          int counter =1;
          int pages = 0;
          
          for(int x:arr){
              pages+=x;
              if(pages>limit){
                  counter++;
                  pages=x;
              }
          }
          
          if(counter<=k){
              ans=limit;
              end=limit-1;
          }
          else{
              start=limit+1;
          }
          
          
      }
      
      return ans;
      
    }
};