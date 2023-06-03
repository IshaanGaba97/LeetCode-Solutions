class Solution {
public:
    // total time is parent + max(child nodes);
    int dfs(int rootnode, unordered_map<int, vector<int>> &adj, vector<int> &itime){
        int rootTime = itime[rootnode];
        int mx = 0;
        
        for(auto it : adj[rootnode]){
            mx = max(mx, dfs(it, adj, itime));
        }
        
        return rootTime + mx;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        
        //creating a n-ary tree
        for(int i = 0; i < manager.size(); i++){
            if(i == headID) continue;
            adj[manager[i]].push_back(i);
        }
        
        // calling dfs to get max out of all the childs
        int ans = dfs(headID, adj, informTime);
        return ans;
    }
};