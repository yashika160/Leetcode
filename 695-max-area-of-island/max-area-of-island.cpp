class Solution {
public:

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    int BFS(int row, int column, vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n) {
        int ans = 1;
        queue<pair<int, int>> q;
        q.push({row, column});
        visited[row][column] = true;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] == false && grid[newRow][newCol] == 1) {
                    q.push({newRow, newCol});
                    ans += 1;
                    visited[newRow][newCol] = true;
                }
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m + 1, vector<bool> (n + 1, false));
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == false && grid[i][j] == 1) {
                    int area = BFS(i, j, grid, visited, m, n);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};