class Solution {
public:
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
            for(int i=0;i<size;i++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int dist = q.front().second;
                q.pop();
                if(row+1<n && vis[row+1][col]==0){
                    q.push({{row+1,col},dist+1});
                    vis[row+1][col]=1;
                    ans[row+1][col]=dist+1;
                }
                if(row-1>=0 && vis[row-1][col]==0){
                    q.push({{row-1,col},dist+1});
                    vis[row-1][col]=1;
                    ans[row-1][col]=dist+1;
                }                
                if(col+1<m && vis[row][col+1]==0){
                    q.push({{row,col+1},dist+1});
                    vis[row][col+1]=1;
                    ans[row][col+1]=dist+1;
                } 
                if(col-1>=0 && vis[row][col-1]==0){
                    q.push({{row,col-1},dist+1});
                    vis[row][col-1]=1;
                    ans[row][col-1]=dist+1;
                }                 
            }
        }
        return ans;
        
    }
};