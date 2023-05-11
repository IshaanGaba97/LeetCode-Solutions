class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int> diff(n);
        for(int i = 0; i < n; i++){
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            if(diff[i] == 0){
                count++;
            } else if (additionalRocks >= diff[i]){
                additionalRocks = additionalRocks - diff[i];
                count++;
            }
        }
        return count;
    }
};