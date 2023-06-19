class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitude(n+1, 0);
        for(int i = 1; i < altitude.size(); i++)
            altitude[i] = altitude[i-1] + gain[i-1];
        return *max_element(altitude.begin(), altitude.end());
    }
};