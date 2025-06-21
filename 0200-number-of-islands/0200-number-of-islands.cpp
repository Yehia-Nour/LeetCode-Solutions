class Solution {
public:
    bool is_valid(int r, int c, vector<vector<char>> &grid) {
        return r >= 0 && r < grid.size() &&
               c >= 0 && c < grid[0].size();
    }

    void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        if (!is_valid(r, c, grid) || grid[r][c] != '1' || visited[r][c]) return;

        visited[r][c] = true;

        int dr[] { -1, 0, 1, 0 };
        int dc[] { 0, 1, 0, -1 };
        for (int d = 0; d < 4; ++d)
            dfs(r + dr[d], c + dc[d], grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int count = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    dfs(r, c, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
