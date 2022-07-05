class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int>& nums, int idx, vector<int>& ds){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        func(nums, idx+1, ds);
        ds.pop_back();
        func(nums, idx+1, ds);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        func(nums, 0, ds);
        return ans;
    }
};