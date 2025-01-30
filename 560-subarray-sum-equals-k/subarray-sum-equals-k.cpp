class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        //similar to zero sum subarray (gfg)
        //? https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
        unordered_map<int,int> mp;
         int sum=0;
        int count=0;
    
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==k) count++;
            
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
                mp[sum]++; //increase the count for that sum
            }
            
            else{
                // mp.insert({sum,1});
                mp[sum]++;
            }
        }
        return count;
    }
};