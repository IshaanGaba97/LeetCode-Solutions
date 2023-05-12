class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid2, vector<vector<int>>& grid1, int &flag){
        int n = grid2.size();
        int m = grid2[0].size();
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(grid1[r][c] != 1){
                flag = 0;
            }
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && grid2[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
//     vector<int> dr = {0, 1, -1, 0};
//     vector<int> dc = {1, 0, 0, -1};
//         void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid2, vector<vector<int>>& grid1, int &flag){
//         vis[row][col] = 1;
//         if(grid1[row][col] != 1){
//             flag = 0;
//         }
            
//         for(int i = 0; i < 4; i++){
//             int nr = row + dr[i];
//             int nc = col + dc[i];
//             if(nr < grid2.size() && nr >= 0 && nc < grid2[0].size() && nc >= 0 && !vis[nr][nc] && grid2[nr][nc] == 1){
//                 dfs(nr, nc, vis, grid2, grid1, flag);
//             }
//         }
//     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid2[row][col] == 1){
                    int flag = 1;
                    // dfs(row, col, vis, grid2, grid1, flag);
                    bfs(row, col, vis, grid2, grid1, flag);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};