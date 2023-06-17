class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long maxi = 0;
        map<int, int> mp;
        
        for(int i = 0; i < k; i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() == k)
        maxi = max(sum, maxi);
        
        for(int i = 1; i <= nums.size()-k; i++){
            mp[nums[i-1]]--;
            if(mp[nums[i-1]] == 0) mp.erase(nums[i-1]);
            sum = sum - nums[i-1];
            
            mp[nums[i+k-1]]++;
            sum = sum + nums[i+k-1];
            
            if(mp.size() == k)
            maxi = max(sum, maxi);
        }
        
        return maxi;
    }
};