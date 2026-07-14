class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 || row==n-1 || col==0 || col==m-1){
                    if(board[row][col]=='O'){
                        q.push({row,col});
                        vis[row][col]=1;
                    }
                }
            }
        }
        vector<int>dr={-1,0,+1,0};
        vector<int>dc={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
            }
        }
    }
};