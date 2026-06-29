class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>adj;
        queue<pair<int,int>>q;
        int mini=0;
        int fresh=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 ){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(fresh==0)return 0;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto& dir: directions){ 
                    int nx=x+dir.first,ny=y+dir.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
            mini++;
        }
        return fresh==0? mini: -1;


    }
};
