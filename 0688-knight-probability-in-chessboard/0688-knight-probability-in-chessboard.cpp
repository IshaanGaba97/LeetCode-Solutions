class Solution {
public:
    vector<vector<int>> dir = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double dp[26][26][101];
  
    double knightProbability(int n, int k, int row, int column) {
        
        return find(n, k, row, column);
    }

    double find(int n, int k, int row, int col)
    {
        if(row < 0 || row > n-1 || col < 0 || col > n-1)
        return 0;
        if(k == 0)
        return 1;

        if(dp[row][col][k] != 0)
        return dp[row][col][k];

        double rate = 0.0;
        for(int i = 0; i < 8; i++)
        {
            rate += 0.125 * find(n , k-1, row+dir[i][0], col+dir[i][1]);
        }
        return dp[row][col][k] = rate;
    }
};