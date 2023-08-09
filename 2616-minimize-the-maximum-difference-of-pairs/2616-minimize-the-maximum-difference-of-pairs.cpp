class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums), end(nums));
        int l = 0, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            
            int cnt = 0;
            for (int i = 0; i+1 < size(nums) && cnt < p; ++i)
                if (nums[i+1] - nums[i] <= m)
                    ++cnt, ++i;
            
            if (cnt == p) r = m;
            else l = m+1;
        }
        return r;
    }
};