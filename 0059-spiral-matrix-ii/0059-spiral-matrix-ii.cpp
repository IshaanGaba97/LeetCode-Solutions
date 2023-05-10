class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int r = n, c = n;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = r-1;
        int endingCol = c-1;

        int total = r * c;
        int cnt = 0;
        int put = 1;
        while (cnt < total && put <= r*c)
        {
        // startingRow 
        for(int i = startingCol; i <= endingCol && cnt < total; i++)
        {
            matrix[startingRow][i] = put++;
            cnt++;
        }
        startingRow++;

        // endingCol 
        for(int i = startingRow; i <= endingRow && cnt < total; i++)
        {
            matrix[i][endingCol] = put++;
            cnt++;
        }
        endingCol--;

        // endingRow
        for(int i = endingCol; i >= startingCol && cnt < total; i--)
        {
            matrix[endingRow][i] = put++;
            cnt++;
        }
        endingRow--;

        // startingCol 
        for(int i = endingRow; i >= startingRow && cnt < total; i--)
        {
            matrix[i][startingCol] = put++;
            cnt++;
        }
        startingCol++;
        }
        return matrix;
    }
};

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int>result;

//         int r=matrix.size();
//         int c=matrix[0].size();

//         int startingRow = 0;
//         int startingCol = 0;
//         int endingRow = r-1;
//         int endingCol = c-1;

//         int total = r * c;
//         int cnt = 0;
        
//         while (cnt < total)
//         {
//         // startingRow 
//         for(int i = startingCol; i <= endingCol && cnt < total; i++)
//         {
//             result.push_back(matrix[startingRow][i]);
//             cnt++;
//         }
//         startingRow++;

//         // endingCol 
//         for(int i = startingRow; i <= endingRow && cnt < total; i++)
//         {
//             result.push_back(matrix[i][endingCol]);
//             cnt++;
//         }
//         endingCol--;

//         // endingRow
//         for(int i = endingCol; i >= startingCol && cnt < total; i--)
//         {
//             result.push_back(matrix[endingRow][i]);
//             cnt++;
//         }
//         endingRow--;

//         // startingCol 
//         for(int i = endingRow; i >= startingRow && cnt < total; i--)
//         {
//             result.push_back(matrix[i][startingCol]);
//             cnt++;
//         }
//         startingCol++;
//         }

//         return matrix;
//     }
// };