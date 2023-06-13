class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        unordered_map<int, vector<int>> row; 
        unordered_map<int, vector<int>> col;
        
        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = 0; j < m; j++){
                temp.push_back(grid[i][j]);
            }
            row[i] = temp;
        }
        
        for(int i = 0; i < m; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                temp.push_back(grid[j][i]);
            }
            col[i] = temp;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == col[j]){
                    count++;
                }
            }
        }
        
        return count;
    }
};