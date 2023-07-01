class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        
        int s = 0, e = n-1;
        while(s < e){
            if(nums[s] < nums[e]) { // to check already sorted array
                return nums[s];
            }
            int mid = s + (e-s)/2;
            // calculating next and prev to mid
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            // now check if mid == smallest element
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
                return nums[mid];
            } 
            if(nums[s] <= nums[mid]){
                s = mid + 1;
            } else if (nums[mid] <= nums[e]){
                e = mid - 1;
            }
        }
        return nums[s];
    }
};