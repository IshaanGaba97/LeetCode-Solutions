bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int binarySearch(vector<vector<int>> &events, int i, int lowThres) {
        int left = i + 1, right = events.size() - 1;

        int result = events.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (events[mid][0] > lowThres) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    int solveRec(vector<vector<int>> &events, int i, int k, vector<vector<int>> &dp) {
        if (i == events.size()) return 0;

        if (k == 0) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        // int nextIndex = events.size();
        int nextIndex = binarySearch(events, i, events[i][1]);
        // for (int j = i + 1; j < events.size(); j++) {
        //     if (events[j][0] < minValue && events[j][0] > events[i][1]) {
        //         minValue = min(minValue, events[j][0]);
        //         nextIndex = j;
        //     }
        // }

        return dp[i][k] = max(events[i][2] + solveRec(events, nextIndex, k - 1, dp),
        solveRec(events, i + 1, k, dp));
    }

    int maxValue(vector<vector<int>> &events, int k) {
        sort(events.begin(), events.end());

        // Optimization 1: dp
        // Optimization 2: binary search

        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));

        return solveRec(events, 0, k, dp);
    }
};