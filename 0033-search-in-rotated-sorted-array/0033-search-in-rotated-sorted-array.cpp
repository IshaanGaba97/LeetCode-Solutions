class Solution {
public:
    int getPivot(vector<int>& nums){
        int s = 0, e = nums.size()-1;
        while(s < e){
            int m = s + (e-s)/2;
            if(nums[m] >= nums[0]){
                s = m + 1;
            }else{
                e = m;
            }
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target){
        int start = s;
        int end = e;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] < target){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;

    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums);

        if(target >= nums[pivot] && target <= nums[n-1]){      // on second line
            return binarySearch(nums, pivot, n-1, target);
        } else {
            return binarySearch(nums, 0, pivot-1, target);  //on first line
        }

    }
};