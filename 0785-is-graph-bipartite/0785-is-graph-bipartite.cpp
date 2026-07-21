class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        queue<pair<int,int>> q;
        for(int k=0;k<n;k++){
            if(vis[k]!=-1)continue;
            q.push({k,0});
            vis[k]=0;
            while(!q.empty()){
                int cur=q.front().first;
                int cur_color=q.front().second;
                int next_color=-1;
                if(cur_color==0)next_color=1;
                else next_color=0;
                q.pop();
                for(auto next: graph[cur]){
                    if(vis[next]==-1){
                        q.push({next,next_color});
                        vis[next]=next_color;
                    }
                    else if(vis[next]==cur_color)return false;
                }
            }
        }
        return true;
    }
};