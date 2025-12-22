class Solution {
public:
    void dfs(int i, int j, int color, int initcolor,vector<vector<int>>&image){
       if(i<0 || j<0 || i>= image.size() || j>= image[0].size() || image[i][j]!=initcolor)return;
       image[i][j]=color;
       dfs(i+1,j,color,initcolor,image);
       dfs(i,j+1,color,initcolor,image);
       dfs(i-1,j,color,initcolor,image);
       dfs(i,j-1,color,initcolor,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color) dfs(sr,sc,color,image[sr][sc],image);
        return image;
    }
};