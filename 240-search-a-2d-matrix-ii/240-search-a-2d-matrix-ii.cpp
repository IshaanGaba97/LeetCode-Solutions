class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = 0;
        if(m != 0){
            n = matrix[0].size();
        }                  
        if(m == 0 || n == 0)    return false;                                                  
        int r = m-1;    // r = matrix.size()-1;
        int c = 0;                  // c = 0;
        while(r >= 0 && c < n){
            if(matrix[r][c] == target) return true;
            
            else if(matrix[r][c] > target){
                r--;
            }
            else{
                c++;
            }
        }
        return false;
    }
};