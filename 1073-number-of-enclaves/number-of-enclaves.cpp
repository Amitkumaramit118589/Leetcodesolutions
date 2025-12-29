class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(grid);
        
        function<void(int, int)> DFS = [&](int i, int j) {
            vis[i][j] = 0;
            if(i+1 < n && vis[i+1][j]) {
                DFS(i+1, j);
            }
            if(i-1 >= 0 && vis[i-1][j]) {
                DFS(i-1, j);
            }
            if(j+1 < m && vis[i][j+1]) {
                DFS(i, j+1);
            }
            if(j-1 >= 0 && vis[i][j-1]) {
                DFS(i, j-1);
            }
        };

        for(int i=0; i<n; i++) {
            if(vis[i][0]) DFS(i, 0);
            if(vis[i][m-1]) DFS(i, m-1);
        }
        for(int i=0; i<m; i++) {
            if(vis[0][i]) DFS(0, i);
            if(vis[n-1][i]) DFS(n-1, i);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += count(vis[i].begin(), vis[i].end(), 1);
        }
        return ans;
    }
};