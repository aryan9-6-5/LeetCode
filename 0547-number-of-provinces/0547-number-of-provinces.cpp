class Solution {
public:
    int count=0;
    void dfs(int source,vector<int>& vis,vector<vector<int>>& edges){
        vis[source]=1;
        for(int i=0;i<edges.size();i++){
            if(edges[source][i]==1 && vis[i]==0){
                dfs(i,vis,edges);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& edges) {
        vector<int>vis(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            if(vis[i]==0){
                dfs(i,vis,edges);
                count++;
            }
        }
        return count;
    }
};