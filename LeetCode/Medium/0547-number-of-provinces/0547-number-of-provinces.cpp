class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        int cnt = 0;
        int ans = 0;

        int i = 0;
        while (cnt < vis.size()){
            // ans++;
            if(!vis[i]){
                dfs(i,isConnected,vis,cnt);
                ans++;
            }
            i++;
        }
        return ans;
    }

    void dfs(int node, vector<vector<int>>& m, vector<int> &vis, int &cnt) {
        if (vis[node]) {
            return;
        }

        cnt++;
        vis[node] = 1;
        for (int i = 0; i < m[node].size(); i++) {
            if (node == i)
                continue;
            if (vis[i])
                continue;
            // if(m[node][])
            if (m[node][i] == 1) {
                dfs(i, m, vis, cnt);
            }
        }
        return;
    }
};