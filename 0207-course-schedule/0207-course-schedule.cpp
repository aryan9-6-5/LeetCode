class Solution {
private:
    bool dfs(int source,vector<int>& vis, vector<int>& path,vector<vector<int>>& adj){
        vis[source]=1;
        path[source]=1;
        for(auto it: adj[source]){
            if(vis[it]==-1){
                if(dfs(it, vis, path, adj)==true)return true;
            }
            else if(path[it]==1)return true;
        }
        path[source]=0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> vis(n,-1);
        vector<int> path(n,0);
        vector<vector<int>> adj(n);
        for(vector<int> &a : pre){
            int u=a[1];
            int v=a[0];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(i,vis,path,adj))return false;
            }
        }
        return true;
    }
};