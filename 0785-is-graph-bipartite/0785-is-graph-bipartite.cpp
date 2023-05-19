class Solution {
public:
    bool dfsCheck(vector<int>& color, int n, int node, vector<vector<int>>& graph){
        if(color[node] == 0) color[node] = 1;
        for(auto it : graph[node]){
            if(color[it] == 0){
                color[it] = -color[node];
                if(!dfsCheck(color, n, it, graph)) return false;
            } else if(color[it] == color[node]){
                return false;
            }  
        }
        return true;
    }
    
    // 1 , -1 are colors
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        for(int i = 0; i < n; i++)  //traverse each component
        {
            if(color[i]) continue;
            if(!dfsCheck(color, n, i, graph))
                return false;
        }
        return true;
    }
};