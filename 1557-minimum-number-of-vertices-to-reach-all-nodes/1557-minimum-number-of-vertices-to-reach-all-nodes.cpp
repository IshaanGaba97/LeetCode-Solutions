class Solution {
public:
        void dfs(int node, vector<vector<int>>& edges, vector<int> adj[], vector<int> &vis1){
            vis1[node] = 1;
            for(auto it : adj[node]){
                if(!vis1[it]){
                    dfs(it, edges, adj, vis1);
                }
            }
        }

        void toposort(int node, vector<vector<int>>& edges, vector<int> adj[], stack<int> &st, vector<int> &vis){
            vis[node] = 1;
            for(auto it : adj[node]){
                if(!vis[it]){
                    toposort(it, edges, adj, st, vis);
                }
            }
            st.push(node);
        }
    
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> vis(n, 0);
        //calculate toposort
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(!vis[i])
                toposort(i, edges, adj, st, vis);
        }
        
        vector<int> vis1(n, 0);
        vector<int> ans;
        //calculating the least indegree nodes which connect others             
	    while(!st.empty()){
            int tp = st.top();
            st.pop();
            if(!vis1[tp]){
                dfs(tp, edges, adj, vis1);
                ans.push_back(tp);
            }
	    }
        
        return ans;
    }
};