class Solution {
public:

//!Way-1 worst Case Time -> O(n^2)
//fuucn that will check count of keys .If count is greater than k return false else true
    // bool checkCount(unordered_map<int , int > mp , int k ){
    //     for(auto x : mp){
    //         if(x.second > k) return false;
    //     }
    //     return true;
    // }

    // int maxSubarrayLength(vector<int>& nums, int k) {
    //     //!we used sliding window

    //     unordered_map<int , int > mp ; //key-> digits and value->counts
    //     int ans=INT_MIN;
    //     int end=0,start=0;

    //     while(end < nums.size()){
    //         mp[nums[end]]++;
    //         bool good = checkCount(mp,k);
         
    //      //if subarr not good, reduce window until subarr is not good
    //         while(!good && start<=end){
    //             mp[nums[start]]--;
    //             good=checkCount(mp,k);
    //             start++;
    //         }
            
    //         //now we have good subarray, compare length
    //         ans=max(ans,1+(end-start));

    //         end++; //increase window 
    //     }
    //     return ans;
    // }

    //!Way-2 Time O(n)
    //similar to way-1 but we changed the way how we were checking for is subarr good or not
    int maxSubarrayLength(vector<int>& nums, int k) {
        //!we used sliding window

        unordered_map<int , int > mp ; //key-> digits and value->counts
        int ans=INT_MIN;
        int end=0,start=0;
        bool good = true;
        while(end < nums.size()){
             
            mp[nums[end]]++;
             
             //if any keys count exceeds k , make good false
            if(mp[nums[end]] > k) good=false;
           //Note-> max the count exccedd wil be 1 as we are checking it ine ach iteration
         
         //if subarr not good, reduce window until subarr is not good
            while(!good && start<=end){
                mp[nums[start]]--;
                //as we are checknng for good in each itartion , the count will be excceed maximum by 1 only
                //so after reducing the count of exceeded key , its count will become k itself
                //so below if condiiton chcks this , if any key count becoms k after reducing its count , then it is a key due to which subarr is not good and as its count is not reduced , subarr is good now
                if(mp[nums[start]]==k) good=true;

                start++;
            }
            
            //now we have good subarray, compare length
            ans=max(ans,1+(end-start));

            end++; //increase window 
        }
        return ans;
    }
};