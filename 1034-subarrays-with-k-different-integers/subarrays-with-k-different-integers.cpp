class Solution {
public:
    
    int getCount(vector<int> nums,int k){
        unordered_map<int,int>mp;
        int start=0,end=0;
        int uniq_count=0,total=0;
        int n=nums.size();
        while(end < n){
            if(mp[nums[end]]==0) uniq_count++; //when unique ele (unique ele will have its freq =0)
            mp[nums[end]]++;

            while(uniq_count==k){
                total+= (n - end); 
                mp[nums[start]]--;
                if(mp[nums[start]]==0) uniq_count--; //so that this can be treated as unique as its freq is 0 now
                start++;
            }
            end++;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //logic we will use is this
        //suppose size of arr is 5
        //we have to find sub arr with k= 2 (exactly two diff integer)
        //instead of finding exact 2 , we will find for subarr with atleast 2 different elements
        //we will also find cout for atleast (k+1) i.e, atleast 3 diff elemenst
        //?subb arr with atleast 2( 2 or more than 2) will have count of ->subarr(2)(2 diff ele) + subarr(3)(3 diff ele) + subarr(4)(4 diff ele) + subarr(5)(5 diff ele)

        //similarly for atleast 3 will have count of -> subarr(3) + subarr(4) + subarr(5);

        //now if we subtract , count of atleast 2 and atleast 3 we will get count for exactly k=2
        // subarr(2)+ subarr(3)+subarr(4)+subarr(5) - subarr(3) - subarr(4)-subarr(5)  ===> subarr(2)
     
     int count_k=getCount(nums,k);
     int count_k1=getCount(nums,k+1);

     return count_k-count_k1;

    }
};