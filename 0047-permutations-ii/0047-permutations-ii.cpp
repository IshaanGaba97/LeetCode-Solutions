class Solution {
public:
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        } 
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        set<vector<int>> st;
        for(auto it : ans){
            st.insert(it);
        }
        vector<vector<int>> res;
        for(auto it : st){
            res.push_back(it);
        }
        return res;
    }
};


