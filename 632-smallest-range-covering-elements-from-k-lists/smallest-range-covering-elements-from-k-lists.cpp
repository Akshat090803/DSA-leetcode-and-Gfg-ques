class Solution {
public:
//Logic we put first ele of each row in minHeap
//the rnage will be the minimum most ele and the maxEle
//for minimum wecreate a minHeap 
//and for max we just take variable max_
//pop minimum form heap , calculate range by subtracting max and min and comapre it with previous range difference
//if current range is smaller, update range
//and push next adjacent ele of the minimum ele to reduce the range size
//for decreassing the range size (decrease the sum between min and max)we have to increase the min or decrease the max
//as list is in ascending sorted order we increase the min
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,pair<int,int>>> temp;
        int max_=INT_MIN;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i][0],{i,0}});
            max_=max(nums[i][0],max_);
        }
       
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap(temp.begin(),temp.end());
        vector<int>ans(2);
        int diff=INT_MAX;

        while(true){
            pair<int,pair<int,int>>Ele1=minHeap.top();
            minHeap.pop();
           
           //for smallest range if current range is smaller in size update range
            if((max_-Ele1.first) < diff){
                ans[0]=Ele1.first;
                ans[1]=max_;
                diff=max_-Ele1.first;
            }

            int i1=Ele1.second.first;
            int j1=Ele1.second.second;
         
         //if for any row adding next ele go out of bound means end the loop
            if(j1+1>=nums[i1].size()) break;
            else{
                minHeap.push({nums[i1][j1+1],{i1,j1+1}});
                //comapre adjacent ele with max;
                // if adjacent ele is bigger than it will be max
                max_=max(nums[i1][j1+1],max_);
            }
           

        }
        return ans;
    }
};