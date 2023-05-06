class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1000000007;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> pow(n, 1);
        for(int i = 1; i < n; i++){
            pow[i] = (pow[i-1]*2) % mod;
        }
        int left = 0, right = n-1;
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                ans += pow[right-left] % mod;
                ans = ans % mod;
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};