class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            int gs = it.first;
            vector<int> vec = it.second;
            vector<int> temp;
            for(int i = 0; i < vec.size(); i++){
                temp.push_back(vec[i]);
                if(temp.size() == gs){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};