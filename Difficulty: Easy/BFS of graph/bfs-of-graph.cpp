class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        vector<int> ans;
        q.push(0);
        int vis[adj.size()] = {0};
        vis[0]=1;
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(int  i = 0; i<adj[curr].size(); i++){
                if(!vis[adj[curr][i]]){
                    q.push(adj[curr][i]);
                    vis[adj[curr][i]]=1;
                }
            }
        }
        return ans;
    }
};