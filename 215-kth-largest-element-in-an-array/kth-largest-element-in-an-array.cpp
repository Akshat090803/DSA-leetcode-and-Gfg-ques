class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //! similar to kth smallest ele ques (gfg) (see that ques for detailed explanation of soln)
        //?for Kth smallest
        // use maxHeap and push first k ele in it
        // for n-k to n compare and do pop push if arr[i] < pq.top() (smaller
        // than)

        //?for Kth largest
        // use minHeap and push first k ele in it
        // for n-k to n compare and do pop push if arr[i] > pq.top() (greater
        // than)

        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++) pq.push(nums[i]);

        for(int i=k;i<nums.size();i++){
            if( nums[i] > pq.top() ){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};