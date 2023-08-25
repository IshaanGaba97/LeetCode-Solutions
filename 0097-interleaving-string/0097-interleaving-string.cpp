class Solution {
public:
    int dp[102][102];
    bool rec(int i, int j, int k, string& s1, string &s2, string &s3)
    {
        if((k == s3.size()) && (i == s1.size()) && (j == s2.size()))
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool take_i = false, take_j = false;
        if(i < s1.size() && k < s3.size())
        {
            if(s1[i] == s3[k])
                take_i = rec(i + 1, j, k + 1, s1, s2, s3);
        }
        if(j < s2.size() && k < s3.size())
        {
            if(s2[j] == s3[k])
                take_j = rec(i, j + 1, k + 1, s1, s2, s3);
        }
        return dp[i][j] = (take_i || take_j);
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, s1, s2, s3);
    }
};