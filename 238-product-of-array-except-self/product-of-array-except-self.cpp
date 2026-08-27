class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
       
         for(int i =1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
            int j = n-i-1;    
            if(j==n-1) continue;
            else suffix[j]=suffix[j+1]*nums[j+1];
            }
            
            for(int i=0;i<n;i++){
                nums[i]=prefix[i]*suffix[i];
            }

            return nums;
    }
};