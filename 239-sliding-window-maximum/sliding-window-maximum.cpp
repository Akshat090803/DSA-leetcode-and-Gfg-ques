class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start=0;
        int end=k-1;
        deque<int> dq;
        vector<int>ans;
//processing first window
     
          for(int i=start;i<=end;i++){
             if(dq.empty()) dq.push_back(i);
             else{
             
                while(!dq.empty() && nums[i]>nums[dq.back()]){ 
                    dq.pop_back();
                }

                dq.push_back(i);
             }
        }

//as we have proccessed first window
        // ans.push_back(nums[dq.back()]);
         ans.push_back(nums[dq.front()]);
        start++;
        end++;

        while(end<nums.size()){

            //remove all small
            while(!dq.empty() && nums[end]>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(end); //this can be max for upcoming window and if not it will be rmeoved in  next iterations above while loop to remove small ele   

            if(dq.front() < start){
                dq.pop_front();
            }

            ans.push_back(nums[dq.front()]);

            start++;
            end++;

        }
return ans;
    }
};