class Solution {
    public int numIslands(char[][] grid) {
        int n=grid.length,count=0;
        int m=grid[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;
    }
    public void dfs(char[][] grid, int i,int j, int n,int m){
        if(i<0 || i>=n || j<0 || j>=m|| grid[i][j]!='1' ) return;
        grid[i][j]='0';
        int[] row={1,0,0,-1};
        int[] col={0,1,-1,0};
        for(int x=0;x<4;x++){
            dfs(grid,i+row[x],j+col[x],n,m);
        }
    }
}
