class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            if(k == nums[l] + nums[r]){
                count++; l++; r--;
            } else if(k > nums[l] + nums[r]){
                l++;
            } else {
                r--;
            }
        }
        return count;
    }
};