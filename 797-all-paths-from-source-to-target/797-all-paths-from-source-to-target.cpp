class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res, int curr){
        if(curr == graph.size()-1){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < graph[curr].size(); i++){
            vector<int> v = graph[curr];
            path.push_back(v[i]);
            dfs(graph, path, res, v[i]);
            path.pop_back();
            
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size() == 0) return{};
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(graph, path, res, 0);
        return res;
    }
};