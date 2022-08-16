class Solution {
public:
    void recurPermute(vector<int>& nums, vector<int>& ds, int freq[], vector<vector<int>>& ans){
        
        for(int i = 0; i < nums.size(); i++){
            if(ds.size() == nums.size()){
                ans.push_back(ds);
                return;
            }
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(nums, ds, freq, ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i = 0; i < nums.size(); i++) freq[i] = 0;
        recurPermute(nums, ds, freq, ans);
        return ans;
    }
};