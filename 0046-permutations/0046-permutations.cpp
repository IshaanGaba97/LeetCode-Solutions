class Solution {
public:
    unordered_map<string, int> memo;
    string generateKey(vector<int>& nums, int index) {
        string key = to_string(index) + ",";
        for (int i = 0; i < nums.size(); i++) {
            key += to_string(nums[i]) + ",";
        }
        return key;
    }
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        } 
        string key = generateKey(nums, index);
        if (memo.count(key)) {
            ans.push_back(nums);  // Reuse the previously calculated permutation
            return;
        }
        
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
         memo[key] = 1;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};