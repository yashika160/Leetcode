class Solution {
public:

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    void BFS(int row, int column, vector<vector<char>> &grid, vector<vector<bool>> &visited, int m, int n) {
        queue<pair<int, int>> q;
        q.push({row, column});
        visited[row][column] = true;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newRow = r + dr[i];
                int newColumn = c + dc[i];
                if(newRow >= 0 && newRow < m && newColumn >= 0 && newColumn < n && grid[newRow][newColumn] == '1' && visited[newRow][newColumn] == false) {
                    q.push({newRow, newColumn});
                    visited[newRow][newColumn] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m + 1, vector<bool> (n + 1, false));
        int connectedIslands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    BFS(i, j, grid, visited, m, n);
                    connectedIslands++;
                }
            }
        } 
        return connectedIslands;
    }
};