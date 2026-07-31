class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        int i = 0;

        while (i < n) {
            if (!vis[i]) {
                int vertices = 0;
                int edges = 0;

                // vis[i]=1;
                // edges += adj[i].size();
                dfs(i,adj,vertices,edges,vis);
                edges /=2;
                if(edges  == vertices*(vertices-1)/2){
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }

    void dfs(int node, vector<int> adj[], int & vertices, int & edges,vector<int> &vis) {
        // if(vis[node]) return;
        edges+=adj[node].size();
        vertices++;
        vis[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            if (vis[adj[node][i]])
                continue;
            dfs(adj[node][i], adj, vertices, edges,vis);
        }
    }
};