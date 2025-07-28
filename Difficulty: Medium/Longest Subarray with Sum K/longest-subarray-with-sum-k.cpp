class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int len=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==k) len=max(len,i+1);
            
            int toFindSum = sum-k;
           if(mp.find(toFindSum) != mp.end()){
               int ind=mp[toFindSum];
               len=max(len,i-ind);
           }
           
           if (mp.find(sum)==mp.end()){
               mp[sum]=i;
           }
        }
        
        return len;
    }
};