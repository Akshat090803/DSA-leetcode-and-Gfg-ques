class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //we use sliding window (will work only when eles are positive as given in constraints)
        //we keep a variable product =1 initially and start=end=0(first index)
        // we increase the window size by doing end++ until product is small than k
        //if product is equal or greater than k , we decrease the window size by start++ until product is less than k
        //will increasing window -> product*=arr[end]
        //will reducing window ->product/=arr[start]
        //count in each iteration will be 1+ end-start  i.e, size of window will tells us about no. of subarr
        //for eg : window has one ele {2} sub arr =1
        //4 added to window {2,4} than new subb arr will be {4} and {2,4}
        //6 added to windpw {2,4,6} than new subarr will be {6} , {6,4} , {2,4,6}
        //{2} , {2,4} etc are added in previous iteration
        

     int start=0,end=0,count=0;
     int product=1;
     
     while(end < nums.size()){
        product*=nums[end];

        //reduce size until product is smaller than k
        while(product>=k && start<=end){
            product/=nums[start];
            start++;
        }

        count+= 1+ (end-start);
        end++; //increaase window size
     }
     return count;
    }
};