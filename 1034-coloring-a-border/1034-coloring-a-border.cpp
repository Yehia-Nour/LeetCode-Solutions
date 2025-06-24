class Solution {
private:
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };

public:
	bool isvalid(int r, int c, vector<vector<int>> &grid) {
		if (r < 0 || r >= (int) grid.size())
			return false;
		if (c < 0 || c >= (int) grid[0].size())
			return false;
		return true;
	}

	void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited, int oldcolor) {
		if (!isvalid(r, c, grid) || visited[r][c] || grid[r][c] != oldcolor)
			return;

		visited[r][c] = 1;
		for (int d = 0; d < 4; ++d)
			dfs(r + dr[d], c + dc[d], grid, visited, oldcolor);
	}

    void createBoundries(vector<vector<int>> &grid, vector<vector<bool>> &visited, int newColor) {
		int rows = grid.size(), cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                for (int d = 0; d < 4; d++) {
                    if (!visited[r][c]) continue;
                    int nr = r + dr[d], nc = c + dc[d];
					if (!isvalid(nr, nc, grid) || !visited[nr][nc])	grid[r][c] = newColor;                }
            }
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
		dfs(row, col, grid, visited, grid[row][col]);
        createBoundries(grid, visited, color);

		return grid;
    }
};