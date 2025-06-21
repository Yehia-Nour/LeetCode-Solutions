class Solution {
public:
    bool is_valid(int r, int c, vector<vector<int>> &grid) {
        if (r < 0 || r >= grid.size()) return false;
        if (c < 0 || c >= grid[0].size()) return false;
        return true;
    }

    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if (!is_valid(r, c, grid) || !grid[r][c] || visited[r][c]) return 0;

        visited[r][c] = true;
        int res = 1;
		int dr[] { -1, 0, 1, 0 };
		int dc[] { 0, 1, 0, -1 };
		for (int d = 0; d < 4; ++d)
			res += dfs(r + dr[d], c + dc[d], grid, visited);
        
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        int maxArea = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                maxArea = max(maxArea, dfs(r, c, grid, visited));
            }
        }

        return maxArea;
    }
};