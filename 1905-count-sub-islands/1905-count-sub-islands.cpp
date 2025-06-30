class Solution {
private:
    int dr[4] { -1, 0, 1, 0 };
    int dc[4] { 0, 1, 0, -1 };

    bool is_sub_island;
public:
    bool is_valid(int r, int c, vector<vector<int>> &grid) {
        return r >= 0 && r < grid.size() &&
               c >= 0 && c < grid[0].size();
    }

    void dfs(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited) {
        if (!is_valid(r, c, grid2) || visited[r][c] || !grid2[r][c]) return;

        visited[r][c] = true;

        if (!grid1[r][c]) {
            is_sub_island = false;
        }
        for (int d = 0; d < 4; ++d)
            dfs(r + dr[d], c + dc[d], grid1, grid2, visited);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size(), cols = grid1[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!visited[r][c] && grid2[r][c]) {
                    is_sub_island = true;
                    dfs(r, c, grid1, grid2, visited);
                    if (is_sub_island)
                        count++;
                }
            }
        }

        return count;
    }
};