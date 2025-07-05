class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
          int prefix = arr[0]; //initliase with first ele as for index 1 , prefix will be sum of till index 0
        int total_sum=0;
        
        
         //calculate total sum
        for(int x:arr) total_sum+=x;
        
        //final code
        //first and last index will never eb equilibrium point as they doent have either left or right part 
        for(int i=1;i<arr.size()-1;i++){
            
            int suffix=total_sum - prefix - arr[i]; //for suffix (not including current)
            
            if(prefix==suffix) return i;
            
            prefix+=arr[i]; 
        }
        //!make prefix and suffix array for [1, 2 ,0 ,3] to understand the code
        return -1;
    }
};