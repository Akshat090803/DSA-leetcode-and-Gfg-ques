class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
              int start=0;
  int end=1;
  int n=arr.size();

  
  if(n==1) return 1;

  while(end<n){
    if(arr[start]==arr[end]){
      end++;
    }else{
      start++;
      arr[start]=arr[end];//overwrite the duplicate elements with the next unique element. 
      //by doing this we are also bringing unique element in starting forming first count elements as unique arr
      //forming like this [u1,u2,u3,x,x,x,x,x]
      end++;

    }
  }
  return start+1;
    }
};