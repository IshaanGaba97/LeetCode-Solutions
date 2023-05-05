class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =  grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n));
        vector<int> oneRow(m);
        vector<int> oneCol(n);
        // vector<int> zeroRow(m);
        // vector<int> zeroCol(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    oneRow[i]++;
                    oneCol[j]++;
                } 
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                diff[i][j] = oneRow[i] + oneCol[j] -  (m- oneRow[i]) -  (n-oneCol[j]) ;
            }
        }
        
        return diff;
        
    }
};