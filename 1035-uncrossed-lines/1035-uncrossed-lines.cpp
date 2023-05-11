class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i >= nums1.size() || j >= nums2.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i] == nums2[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, nums1, nums2, dp);
        }
        return dp[i][j] = max(solve(i, j+1, nums1, nums2, dp), solve(i+1, j, nums1, nums2, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        for(int i = 0; i <= n; i++){
            dp[i][m] = 0;
        }
        for(int i = 0; i <= m; i++){
            dp[n][i] = 0;
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                     dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};