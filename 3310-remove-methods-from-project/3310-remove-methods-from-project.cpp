class Solution {
public:
    void dfs(int index,vector<int>& vis, vector<vector<int>>& adj){
        vis[index]=1;
        for(auto i: adj[index]){
            if(vis[i]==-1){
                dfs(i,vis, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& arr) {
        int size=n;
        vector<vector<int>> adj(size);
        vector<int> vis(size,-1);
        for(auto &it : arr){
            adj[it[0]].push_back(it[1]);
        }
        dfs(k,vis,adj);
        for (auto &edge : arr) {
            int u = edge[0];
            int v = edge[1];

            if (vis[u] == -1 && vis[v] == 1) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1)
                ans.push_back(i);
        }        
        return ans;
    }
};