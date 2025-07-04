class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int prev = 0;
    int missingCount = 0;
      int n=arr.size();
    for (int i = 0; i < n; i++) {
        int gap = arr[i] - prev - 1;  // numbers missing between prev and arr[i]
        if (missingCount + gap >= k) {
            return prev + (k - missingCount);
        }
        missingCount += gap;
        prev = arr[i];
    }

    // If k-th missing number is beyond the last element
    return arr[n - 1] + (k - missingCount);
    }
};