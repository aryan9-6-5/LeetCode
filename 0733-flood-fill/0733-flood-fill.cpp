class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const int val=image[sr][sc];
        if (val == color) return image;
        dfs(image,sr,sc,color,val);
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int color,const int val){
        if(i<0 || i>=image.size()|| j<0 || j>=image[0].size() || image[i][j]!=val)return;
        image[i][j]=color;
        dfs(image,i+1,j,color,val);
        dfs(image,i-1,j,color,val);
        dfs(image,i,j+1,color,val);
        dfs(image,i,j-1,color,val);
    }

};