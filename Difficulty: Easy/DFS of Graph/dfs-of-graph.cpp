class Solution {
	public:
	vector<int> dfs(vector<vector<int>> & adj) {
		// Code here
		vector<int> vis(adj.size(),0);
		vector<int> ans;
		
		DFS(0,vis,adj,ans);
		return ans;
	}
	
	void DFS(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans) {
		vis[node] = 1;
		ans.push_back(node);
		for (int i = 0; i<adj[node].size(); i++) {
		    if(vis[adj[node][i]]==1) continue;
		    
			DFS(adj[node][i], vis, adj, ans);
		}
	}
};
