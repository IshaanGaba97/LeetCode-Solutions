class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] < target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};