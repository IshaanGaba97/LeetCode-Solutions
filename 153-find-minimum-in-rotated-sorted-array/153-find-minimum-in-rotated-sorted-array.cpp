class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        if(nums.size() == 1) return nums[0];
        int ans = INT_MAX;
        
        int s = 0, e = nums.size()-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[0] <= nums[m]){
                s = m + 1;
            }
            else{
                ans = min(ans, nums[m]);
                e = m -1;
            }
        }
        return ans;
    }
};