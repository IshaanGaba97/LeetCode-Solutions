class Solution {
public:
    // cycle detection: the nodes which will be the part of the cycle will never be a safe node
    bool dfs(int src,  vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&preVis){
        vis[src] = true;
        preVis[src] = true;
        
        for(auto it : adj[src]){
            if(!vis[it]){
                if(dfs(it, adj, vis, preVis)){
                    return true;
                }
            }
            else if(preVis[it] == true){
                return true;
            }
        }
        preVis[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<bool>vis(n, false);
        vector<bool>preVis(n, false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis, preVis);
            }
        }

        vector<int>safe;
        for(int i=0;i<preVis.size();i++){
            if(!preVis[i]){
                safe.push_back(i);
            }
        }
        return safe;
    }
};