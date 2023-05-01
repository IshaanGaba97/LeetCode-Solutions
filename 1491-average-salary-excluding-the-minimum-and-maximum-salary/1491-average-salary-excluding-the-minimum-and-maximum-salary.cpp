class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        double sum = 0;
        int n = salary.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, salary[i]);
            mini = min(mini, salary[i]);
            sum += salary[i];
        }
        sum = sum - maxi - mini;
        double ans = sum/(n-2);
        return ans;
    }
};