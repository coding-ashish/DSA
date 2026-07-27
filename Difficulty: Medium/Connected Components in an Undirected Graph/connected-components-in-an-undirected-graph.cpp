class Solution {
	public:
	vector<vector<int>> getComponents(int V, vector<vector<int>> & edges) {
		// code here
		vector<int> adj[V];
		vector<int> vis(V, 0);
		
		for (int i = 0 ; i<edges.size(); i++) {
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		
		vector<vector<int>> ans;
		for(int i =0; i<V; i++){
		    vector<int> mini_ans;
		    if(vis[i]) continue;
		    DFS(i,vis,adj,mini_ans);
		    ans.push_back(mini_ans);
		}
		return ans;
	}
	
	void DFS(int node, vector<int> &vis, vector<int> adj[], vector<int> &mini_ans) {
		vis[node] = 1;
		mini_ans.push_back(node);
		for (int i = 0; i<adj[node].size(); i++) {
		    if(vis[adj[node][i]]==1) continue;
		    
			DFS(adj[node][i], vis, adj, mini_ans);
		}
	}
	
};
