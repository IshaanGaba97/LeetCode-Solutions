class Solution {
public:
     bool ans = false;
    void func(int i, int j, vector<vector<char>>& board, string word, int k, int di[], int dj[], vector<vector<int>>& vis){
        if(k == word.size()){
            ans = true;
            return;
        }
        
        for(int ind = 0; ind < 4; ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 && nextj >= 0 && nexti < board.size() && nextj < board[0].size() && !vis[nexti][nextj] && board[nexti][nextj] == word[k]){
                vis[i][j] = 1;
                func(nexti, nextj, board, word, k+1, di, dj, vis);
                vis[i][j] = 0;
            }
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && vis[i][j] == 0){
                    vis[i][j] = 1;
                    func(i, j, board, word, 1, di, dj, vis);
                    vis[i][j] = 0;
                }
            }
        }
        return ans;
    }
 
};