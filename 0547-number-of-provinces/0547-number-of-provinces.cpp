class Solution {
public:
    // void dfs(int node, vector<int> adj[], vector<int> &vis){
    //     vis[node] = 1;
    //     for(auto it : adj[node]){
    //         if(!vis[it]){
    //             dfs(it, adj, vis);
    //         }
    //     }
    // }
    
    void bfs(int node, vector<int> adj[], vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int t = q.front(); 
            q.pop();
            for(auto it : adj[t]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count = 0;
        vector<int> vis(n+1, 0);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                count++;
                // dfs(i, adj, vis);
                bfs(i, adj, vis);
            }
        }
        return count;
    }
};