class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int minutes = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for(int i = 0; i < size; i++) {
                auto cell = q.front(); q.pop();
                int r = cell.first, c = cell.second;

                for(int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];

                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                        rottedThisMinute = true;
                    }
                }
            }

            if(rottedThisMinute) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};