class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    struct cell {
        int r, c;
    };

    bool isvalid(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
    int dist = -1;

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
             vector<cell>& startings) {
        queue<cell> q;
        for (cell& c : startings) {
            visited[c.r][c.c] = true;
            q.push(c);
        }

        for (int level = 0, sz = q.size(); !q.empty(); level++, sz = q.size()) {
            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (!isvalid(nr, nc, grid) || visited[nr][nc] ||
                        grid[nr][nc] != 0)
                        continue;

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            dist++;
        }
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        vector<cell> startings;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == 1)
                    startings.push_back({r, c});
        }
        if (startings.empty() || startings.size() == rows * cols)
            return -1;

        bfs(grid, visited, startings);
        return dist;
    }
};