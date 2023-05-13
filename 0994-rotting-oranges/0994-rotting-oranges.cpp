class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;     //{{r,c}, t}
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1 || grid[i][j] == 2){
                    count++;
                }
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int maxt = 0;
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            maxt = max(maxt, t);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<n && nr>= 0 && nc<m && nc>=0 && vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 2;
                }
            }
        }
        int count2 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 2){
                    count2++;
                }
            }
        }
        if(count == count2) return maxt;
        return -1;
    }
};