class Solution {
public:
    int dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &itime){
        int headID = itime[node];
        int mx = 0;
        for(auto it : adj[node]){
            mx = max(mx, dfs(it, adj, itime));
        }
        return headID + mx;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < manager.size(); i++){
            if(i == headID) continue;
            adj[manager[i]].push_back(i);
        }
        int ans = dfs(headID, adj, informTime);
        return ans;
    }
};