class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int count = 0;
        queue<pair<int,int>> q;
        if(grid[0][0] != 0) return -1;
        q.push({0,0});
        vis[0][0] = 1;
        
        while(!q.empty()){
            count++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                if(r == n-1 && c == n-1) return count;
                
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        int nr = r + i;
                        int nc = c + j;
                        if(nr<n and nc<n and nr>=0 and nc>=0 and grid[nr][nc]==0 and vis[nr][nc]==0){
                            q.push({nr,nc});
                            vis[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};