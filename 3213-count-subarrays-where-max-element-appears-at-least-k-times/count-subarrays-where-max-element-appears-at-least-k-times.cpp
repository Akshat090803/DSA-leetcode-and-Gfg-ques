class Solution {
public:

//Approach 
//extend window jb tk k_count==k
//jb k_count==k , reduce window 
//during reducing the window , 
//    -> count will be count+ = (n-end)
//    -> see why , consider arr [1,2,3,2,3,1,2,3,3,2] and k=2
//    ->first valid subarr wil be at end 4 where k_count will become ==k
//    ->so first valid subarr will range (0,4) and if we see , subarr (0,5) , (0,6) , (0,7) ,(0,8) , (0,9) will also be valid as they will have atleast k max elements ,
//?so it concluldes that valid sub arr will be the valid subarr and subbarrays with  rest remaining  element count = 1 + subarr with remianing arr

//now reduce the size start++ if we see , (1,4) is also a valid subarr as it has K_count==k
//now similarly (1,5) , (1,6) , (1,7) , (1, 8) ,(1,9) will also be valid subarr as they have atleast k max ele
//so reduce the arr  jb tk k_count ==k as it will be the valid subarr and its subarr with rest remaing ele will also be valid
    long long countSubarrays(vector<int>& nums, int k) {
         long long count=0;
         int k_count=0;
         int max_=INT_MIN;
         int n=nums.size();
         for(auto x: nums) max_=max(max_,x);

         int start=0,end=0;
         while(end<n){

            if(nums[end]==max_) k_count++;

            while(k_count==k){
                count+= (n-end); //subarr including itslf and with reamining ele will also be valid subarr
                if(nums[start]==max_){
                    k_count--;
                }
                start++;
            }
            end++;
         }
          

          return count;
         
    }
};