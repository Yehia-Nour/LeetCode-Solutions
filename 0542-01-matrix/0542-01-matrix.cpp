class Solution {
    int dr[4]{ -1, 0, 1, 0 };
    int dc[4]{ 0, 1, 0, -1 };

    bool isvalid(int r, int c, vector<vector<int>> &mat) {
        return r >= 0 && r < mat.size() && c >= 0 && c < mat[0].size();
    }

    struct cell {
        int r, c;
    };

    void bfs(vector<vector<int>> &mat, vector<vector<int>> &dist, vector<cell> &startings) {
        queue<cell> q;
        for (cell &c : startings) {
            q.push(c);
            dist[c.r][c.c] = 0;
        }

        for (int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (!isvalid(nr, nc, mat) || dist[nr][nc] != -1)
                        continue;

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        vector<cell> zeros;

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (mat[r][c] == 0)
                    zeros.push_back({r, c});

        bfs(mat, dist, zeros);
        return dist;
    }
};
