class Solution {
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    struct cell {
        int r, c;
    };

    bool isvalid(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    int bfs(vector<vector<int>>& grid, vector<cell>& startings, int freshCount) {
        int rows = grid.size(), cols = grid[0].size();
        queue<cell> q;
        for (cell& c : startings)
            q.push(c);

        int minutes = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool rottedThisMinute = false;

            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];

                    if (!isvalid(nr, nc, rows, cols) || grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    freshCount--;
                    q.push({nr, nc});
                    rottedThisMinute = true;
                }
            }

            if (rottedThisMinute)
                minutes++;
        }

        return freshCount == 0 ? minutes : -1;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<cell> startings;
        int freshCount = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2)
                    startings.push_back({r, c});
                else if (grid[r][c] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0) return 0;
        return bfs(grid, startings, freshCount);
    }
};
