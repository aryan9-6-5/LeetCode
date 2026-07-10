class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int count=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();
                for(auto it: directions){
                    int dx=x+it.first;
                    int dy=y+it.second;
                    if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]==1){
                        fresh--;
                        grid[dx][dy]=2;
                        q.push({dx,dy});
                    }
                }
            }
            count++;
        }
        if(fresh>0)return -1;
        return count;
    }
};