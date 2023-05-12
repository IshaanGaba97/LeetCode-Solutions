class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size(); 
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && grid[nr][nc] == '1'){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int count = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return count; 
    }
};