class Solution {
public:

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<pair<int, int>, int>> q;

        int sr = entrance[0];
        int sc = entrance[1];

        q.push({{sr, sc}, 0});
        maze[sr][sc] = '+';

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.') {
                    if(nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                        return dist + 1;
                    }
                    q.push({{nr, nc}, dist + 1});
                    maze[nr][nc] = '+';
                }
            }
        }
        return -1;
    }
};