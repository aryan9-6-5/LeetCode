class Solution {
public:
    bool dfs(vector<int>& vis,vector<vector<int>>& graph,int cur,int cur_color){
        vis[cur]=cur_color;
        bool ans;
        for( auto it: graph[cur] ){
            if(vis[it]!=-1){
                if(vis[it]==cur_color)return false;
            }
            else{
                if(!dfs(vis,graph,it,!cur_color)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        bool ans;
        for(int i=0;i<n;i++){
            if(vis[i]!=-1)continue;
            if(!dfs(vis,graph,i,0)) return false;
        }
        return true;
    }
};