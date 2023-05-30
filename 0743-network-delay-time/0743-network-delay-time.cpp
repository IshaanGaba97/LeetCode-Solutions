class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distTo(V+1, 1e9);
        distTo[S] = 0;
        pq.push(make_pair(0,S));
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto it : adj[prev]){
                int next = it[0];
                int nextDist = it[1];
                if(distTo[next] > distTo[prev] + nextDist){
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        return distTo;
        
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        vector<int> distTo(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int d = times[i][2];
            adj[u].push_back({v, d});
        }
        vector<int> time = dijkstra(n, adj, k);
        // int res = -1;
        // for(auto it : dist){
        //     if(it != INT_MAX){
        //         res = max(res, it);
        //     }
        // }
        // return res;
        for(int i=1;i<n+1;i++){
            if(time[i]==1E9){
                return -1;
            }
        }
        return *max_element(time.begin()+1,time.end());
        
    }
};