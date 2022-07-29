class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m != r*c) return mat;
        vector<vector<int>> res(r,vector<int>(c));
        int rptr = 0, cptr = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res[rptr][cptr++] = mat[i][j];
                if(cptr == c){
                    rptr++;
                    cptr = 0;
                }
            }
        }
        return res;
    }
};