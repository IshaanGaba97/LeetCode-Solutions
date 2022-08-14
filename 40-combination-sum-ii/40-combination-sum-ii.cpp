class Solution {
public:
    void combinationRec(int index, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i < arr.size(); i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            if(target < arr[i]) break;
            ds.push_back(arr[i]);
            combinationRec(i+1, target-arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combinationRec(0, target, candidates, ds, ans);
        return ans;
    }
};