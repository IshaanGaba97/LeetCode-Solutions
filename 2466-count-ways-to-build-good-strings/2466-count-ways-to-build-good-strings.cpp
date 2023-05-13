class Solution {
public:
    int mod = 1e9 + 7;
    int f(int sz, int low, int high, int zero, int one, vector<int> &dp){
        
        if(sz > high){
            return 0;
        }
        if(dp[sz] != -1) return dp[sz];
        int ans = 0;
        if(sz >= low && sz <= high) ans = 1;
        ans +=  f(sz+zero, low, high, zero, one, dp);
         
        ans +=  f(sz+one, low, high, zero, one, dp);
        
        
        return dp[sz] = ans % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        int ans = f(0, low, high, zero, one, dp) % mod;
        return ans;
    }
};