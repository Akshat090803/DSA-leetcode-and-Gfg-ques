class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp; // we store sum%k as key and count as value
        // why we store sum%k as key bcoz
        // let k=7;
        // at index x sum is 12 so 12%7=5 map-> {5 : 1}
        // at index y (y>x) sum is 26 so 26%7=5 as 5 is present already in map
        // it means remainder b.w them is same means there is a subarr between
        // index x and y whose sum is divisible by 7 thats why remainder is same
        //  26-12 = 14 means between index x and y there is a subarray whose sum
        //  is 14 that why remainder is same
        // so in if condition we check if (sum%k) exist in map instead of sum-k
        // (which was we dping in count subarr sum eqauls k problem)

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum % k == 0)
                count++;
            // if(nums[])

            // ?Normalize the sum % k to be non-negative
            // consider arr={-1,2,9} k=2 for sum=-1 mod will be -1 so to handle
            // this ensures that you always work with a non-negative key in the hashmap. 
            int mod = ((sum % k) + k) % k;

            if (mp.find(mod) != mp.end()) {
                count = count + mp[mod];
                mp[mod]++;
                // we increase cout of mp[sum%k] key itself as for sum 12 or sum
                // 26 key will be same that is sum%k = 3 is a ley so we are
                // nincreasing that count
            } else {
                mp[mod]++;
            }
        }
        return count;
    }
};