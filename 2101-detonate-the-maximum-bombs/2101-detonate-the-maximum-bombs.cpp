class Solution {
    #define ll long long
public:
    void dfs(int node, unordered_set<int>& vis, unordered_map<int, vector<int>> &adj){
        vis.insert(node);
        for(auto it : adj[node]){
            if(vis.find(it) == vis.end()){
                dfs(it, vis, adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //adj list for graph
        unordered_map<int, vector<int>> adj;
        int n = bombs.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];
                
                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];
                
                ll dist = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
                ll rsq = r1*r1;
                if(rsq >= dist){
                    adj[i].push_back(j);
                }
            }
        }
        int maxi = 0;
        unordered_set<int> vis;
        for(int i = 0; i < n; i++){
            if(vis.find(i) == vis.end()){
                dfs(i, vis, adj);
                int count = vis.size();
                maxi = max(maxi, count); 
                vis.clear();
            }
        }
        return maxi;
    }
};