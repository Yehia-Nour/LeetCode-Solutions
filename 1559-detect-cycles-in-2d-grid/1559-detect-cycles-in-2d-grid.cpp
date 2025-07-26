class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
public:
    bool is_valid(int r, int c, vector<vector<char>> &grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    bool dfs(int r, int c, int pr, int pc, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        visited[r][c] = true;
        
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if (!is_valid(nr, nc, grid) || grid[nr][nc] != grid[r][c]) continue;
            
            if (!visited[nr][nc]) {
                if (dfs(nr, nc, r, c, grid, visited)) return true;
            } else if (nr != pr || nc != pc) {
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!visited[r][c]) {
                    if (dfs(r, c, -1, -1, grid, visited)) return true;
                }
            }
        }
        return false;
    }
};
