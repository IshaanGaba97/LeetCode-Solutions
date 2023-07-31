class Solution {
public:
    //logic: LCS with some modification:
    //along with the LCS also maintain the highest ascii value of the LCS
    //at the end just subtract from the total.... thats it
    #define pii pair<int, int>
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        int total = 0;
        vector<vector<pii>>dp(n1+1, vector<pii>(n2+1, {0, 0}));
        for(int i=0; i<n1; i++){
            total += s1[i];
            for(int j=0; j<n2; j++){
                if(s1[i] == s2[j]){
                    int x = s1[i];
                    dp[i+1][j+1] = {dp[i][j].first + 1, dp[i][j].second + x};
                }
                else{
                    if(dp[i][j+1].first > dp[i+1][j].first) dp[i+1][j+1] = dp[i][j+1];
                    else if(dp[i][j+1].first < dp[i+1][j].first) dp[i+1][j+1] = dp[i+1][j];
                    else{
                        if(dp[i][j+1].second > dp[i+1][j].second) dp[i+1][j+1] = dp[i][j+1];
                        else dp[i+1][j+1] = dp[i+1][j];
                    }
                }
            }
        }
        for(auto i:s2) total += i;
        // cout<<total<<endl;
        return total - 2*dp[n1][n2].second;
    }
};