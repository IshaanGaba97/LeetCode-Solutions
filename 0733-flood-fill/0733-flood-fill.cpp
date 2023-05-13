class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int initColor = image[sr][sc];
        
        vector<vector<int>> vis(n, vector<int>(m, 0));      //visgrid
        vector<vector<int>> ans = image;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;   //{r,c}
        q.push({sr, sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = newColor;
        
        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[nr][nc]==initColor && ans[nr][nc] != newColor){
                    ans[nr][nc] = newColor;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
    
};