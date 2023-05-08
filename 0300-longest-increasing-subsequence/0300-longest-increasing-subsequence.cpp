class Solution {
public:
//     int f(int ind, vector<int>& nums, int bound, vector<vector<int>> &dp){
//         if(ind == nums.size()){
//             return 0;
//         }
//         if(dp[ind][bound+1] != -2) return dp[ind][bound+1];
        
//         int l = -1e9;
//         if(bound == -1 || nums[ind] > nums[bound]){
//            l = f(ind+1, nums, ind, dp) + 1;
//         }
//         int r = f(ind+1, nums, bound, dp);
        
//         return dp[ind][bound+1] = max(l, r);
//     }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        int count = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], lis[j]+1);
                    count = max(count, lis[i]);
                }
            }
        }
        return count;
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -2));
        // return f(0, nums, -1, dp);
        
    }
};

