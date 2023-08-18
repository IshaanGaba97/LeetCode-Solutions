class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
           // make adj list
           vector<set<int>> adj(n);
           for(auto road : roads){
               adj[road[0]].insert(road[1]);
               adj[road[1]].insert(road[0]);
           }
           // traverse
           int best = 0;
           for(int i = 0 ; i < n ; i++){
               for(int j = 0 ; j < n ; j++){
                   if(i == j ) continue;
                   int ans = 0;
                   if(adj[j].find(i) != adj[j].end()){
                       ans = adj[i].size() + adj[j].size() - 1;
                   } else {
                       ans = adj[i].size() + adj[j].size();
                   }
                   best = max(ans, best);
               }
           }
           return best;
    }
};