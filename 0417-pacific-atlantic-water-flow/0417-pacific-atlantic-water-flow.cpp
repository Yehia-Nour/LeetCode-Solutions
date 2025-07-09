class Solution {
    int dr[4] { -1, 0, 1, 0 };
    int dc[4] { 0, 1, 0, -1 };

    bool isvalid(int r, int c, vector<vector<int>> &matrix) {
        if (r < 0 || r >= (int) matrix.size())
            return false;
        if (c < 0 || c >= (int) matrix[0].size())
            return false;
        return true;
    }

    struct cell {
        int r, c;
    };

    void bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<cell> &startings) {
        queue<cell> q;

        for (cell &cell : startings) {
            q.push(cell);
            visited[cell.r][cell.c] = 1;
        }

        for (int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()) {
            while (sz--) {
                int r = q.front().r, c = q.front().c;
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (!isvalid(nr, nc, matrix) || visited[nr][nc] || matrix[r][c] > matrix[nr][nc])
                        continue;

                    q.push( { nr, nc });
                    visited[nr][nc] = 1;
                }
            }
        }
    }
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
		int rows = matrix.size(), cols = matrix[0].size();

		vector<vector<bool>> pacificReachable(rows, vector<bool>(cols));
		vector<vector<bool>> atlanticReachable(rows, vector<bool>(cols));

		vector<cell> pacificStartings, atlanticStartings;

		for (int r = 0; r < rows; r++) {
			pacificStartings.push_back( { r, 0 });
			atlanticStartings.push_back( { r, cols - 1 });
		}
		for (int c = 0; c < cols; c++) {
			pacificStartings.push_back( { 0, c });
			atlanticStartings.push_back( { rows - 1, c });
		}

		bfs(matrix, pacificReachable, pacificStartings);
		bfs(matrix, atlanticReachable, atlanticStartings);

		vector<vector<int>> results;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (pacificReachable[i][j] && atlanticReachable[i][j])
					results.push_back( { i, j });

		return results;
	}
};