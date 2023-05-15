class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indegree(V,0);
	    for(int i = 0; i < V; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        auto it = topoSort(numCourses, adj);
        
        //just return the topo sort if size is equals to node
        if(it.size() == numCourses) return it;
        else return {};
    
    }
};