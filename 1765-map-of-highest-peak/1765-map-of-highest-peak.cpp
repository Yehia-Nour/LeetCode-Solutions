class Solution {
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    bool isvalid(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    struct cell {
        int r, c;
    };

    void bfs(vector<vector<int>> &result, vector<cell> &startings, int rows, int cols) {
        queue<cell> q;
        for (cell &c : startings)
            q.push(c);

        for (int level = 0; !q.empty(); ++level) {
            int sz = q.size();
            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (!isvalid(nr, nc, rows, cols) || result[nr][nc] != -1)
                        continue;

                    result[nr][nc] = result[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, -1));
        vector<cell> waterCells;

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (isWater[r][c] == 1) {
                    result[r][c] = 0;
                    waterCells.push_back({r, c});
                }

        bfs(result, waterCells, rows, cols);
        return result;
    }
};
