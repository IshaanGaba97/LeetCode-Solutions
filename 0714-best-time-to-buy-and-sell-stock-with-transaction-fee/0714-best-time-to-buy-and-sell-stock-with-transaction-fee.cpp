class Solution {
public:
    int f(int i, vector<int>& prices, int buy, vector<vector<int>> &dp, int fee){
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + f(i+1, prices, 0, dp, fee), 0 + f(i+1, prices, 1, dp, fee));
        } else {
            profit = max(prices[i]-fee + f(i+1, prices, 1, dp, fee), 0 + f(i+1, prices, 0, dp, fee));
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, prices, 1, dp, fee);
    }
};