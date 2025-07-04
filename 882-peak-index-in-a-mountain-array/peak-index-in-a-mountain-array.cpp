class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1,ind = -1;
     
        while (start <= end) {
            int mid = end + (start-end) / 2;
            // if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
            //     ind = mid;
            //     break;
            // } else if (arr[mid] < arr[mid + 1]) {
            //     start = mid + 1;
            // } else {
            //     end = mid - 1;
            // }
            if(arr[mid]<arr[mid+1]){
      start=mid+1;
   
    }
    else{
      end=mid-1;
         ind=mid;
    }
        }
        return ind;
    }
};