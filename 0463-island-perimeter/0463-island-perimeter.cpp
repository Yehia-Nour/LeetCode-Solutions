class Solution {
public:
    bool is_valid(int r, int c, vector<vector<int>> &grid) {
        if (r < 0 || r >= grid.size()) return false;
        if (c < 0 || c >= grid[0].size()) return false;
        return true;
    }
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if (!is_valid(r, c, grid) || !grid[r][c]) return 1;
        else if (visited[r][c]) return 0;

        visited[r][c] = true;
        int res = 0;
		int dr[] { -1, 0, 1, 0 };
		int dc[] { 0, 1, 0, -1 };
		for (int d = 0; d < 4; ++d)
			res += dfs(r + dr[d], c + dc[d], grid, visited);
        
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        bool is_land = false;
        int r, c;

        for (int i = 0; i < grid.size(); i++) {
            if (is_land) break;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]){
                    r = i;
                    c = j;
                    is_land = true;
                    break;
                }
            }
        }

		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        return dfs(r, c, grid, visited);
    }
};