class Solution {
public:
    vector<int>dr={-1,0,1,0};
    vector<int>dc={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;
        int dis=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},dis});
                }
            }
        }
        while(!q.empty()){
                int size=q.size();
                int row = q.front().first.first;
                int col = q.front().first.second;
                int dist = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                        q.push({{nr,nc},dist+1});
                        vis[nr][nc]=1;
                        ans[nr][nc]=dist+1;
                    }
                }
        }                
        return ans;
        
    }
};