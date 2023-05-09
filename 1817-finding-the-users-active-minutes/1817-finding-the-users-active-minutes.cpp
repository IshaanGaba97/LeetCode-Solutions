class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        // userid -> times
        unordered_map<int, set<int>> mp;
        for(auto it : logs){
            int userid = it[0];
            int time = it[1];
            mp[userid].insert(time);
        }
        
        unordered_map<int, int> mp2;
        for(auto it : mp){
            int size = it.second.size();
            mp2[size]++;
        }
        for(auto it : mp2){
            ans[it.first-1] = it.second;
        }
        return ans;
    }
};