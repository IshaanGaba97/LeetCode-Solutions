class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i == nums.size()) return dp[i] = true;
        if (dp[i] != -1) return dp[i];
        
        bool res = false;
        
        if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            res = solve(nums, i + 2, dp);
        
        if (!res && i + 2 < nums.size() && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
            res = solve(nums, i + 3, dp);
        
        if (!res && i + 2 < nums.size() && nums[i] +1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
            res = solve(nums, i + 3, dp);
        
        return dp[i] = res;
    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, 0, dp);
    }
};