class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;

        int r=matrix.size();
        int c=matrix[0].size();

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = r-1;
        int endingCol = c-1;

        int total = r * c;
        int cnt = 0;
        
        while (cnt < total)
        {
        // startingRow 
        for(int i = startingCol; i <= endingCol && cnt < total; i++)
        {
            result.push_back(matrix[startingRow][i]);
            cnt++;
        }
        startingRow++;

        // endingCol 
        for(int i = startingRow; i <= endingRow && cnt < total; i++)
        {
            result.push_back(matrix[i][endingCol]);
            cnt++;
        }
        endingCol--;

        // endingRow
        for(int i = endingCol; i >= startingCol && cnt < total; i--)
        {
            result.push_back(matrix[endingRow][i]);
            cnt++;
        }
        endingRow--;

        // startingCol 
        for(int i = endingRow; i >= startingRow && cnt < total; i--)
        {
            result.push_back(matrix[i][startingCol]);
            cnt++;
        }
        startingCol++;
        }

        return result;
    }
};