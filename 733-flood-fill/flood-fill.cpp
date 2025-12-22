class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>>&ans,vector<vector<int>>&image,vector<vector<int>>&visited,int n,int m,int color,int val){
        for(int delRow=-1;delRow<=1;delRow++){
            for(int delCol=-1;delCol<=1;delCol++){
                int newRow = delRow+sr;
                int newCol = delCol+sc;
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && abs(delRow)!=abs(delCol) && !visited[newRow][newCol] && image[newRow][newCol]==val){
                    visited[newRow][newCol] = 1;
                    ans[newRow][newCol] = color;
                    dfs(newRow,newCol,ans,image,visited,n,m,color,val);
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if (image[sr][sc] == color) return image;
        vector<vector<int>>ans = image;
        vector<vector<int>>visited(n,vector<int>(m,0));
        ans[sr][sc] = color;
        int val = image[sr][sc];
        visited[sr][sc] = 1;
        dfs(sr,sc,ans,image,visited,n,m,color,val);
        return ans;
    }
};