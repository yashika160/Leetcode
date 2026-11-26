class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        grid[i][j] = 0;
                    }
                }
            }
        }

        int count = 0;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = r + dx[i];
                int ny = c + dy[i];
                if(nx >= 0 && nx < m  && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
};