class Solution {
public:
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};
    
    int bfs(queue<pair<int, int>> &q, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
     
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && grid[nr][nc] == 1){
                        return level;
                    }
                    else if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && grid[nr][nc] == 0){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            level++;
        }
        
        return level;
    }
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>> &q){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        q.push({row, col});
        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, grid, vis, q);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int, int>> q;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1){
                    dfs(row, col, grid, vis, q);
                    return bfs(q, grid, vis);
                }
            }
        }
        return 0;
    }
};