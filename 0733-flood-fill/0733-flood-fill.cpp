class Solution {
public:
    bool is_valid(int r, int c, vector<vector<int>> &matrix) {
        if (r < 0 || r >= matrix.size()) return false;
        if (c < 0 || c >= matrix[0].size()) return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int oldcolor, int newcolor) {
		if (!is_valid(r, c, matrix) || visited[r][c] || matrix[r][c] != oldcolor) return;

		visited[r][c] = true, matrix[r][c] = newcolor;
		int dr[] { -1, 0, 1, 0 };
		int dc[] { 0, 1, 0, -1 };
		for (int d = 0; d < 4; ++d)
			dfs(r + dr[d], c + dc[d], matrix, visited, oldcolor, newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
		dfs(sr, sc, image, visited, image[sr][sc], color);

		return image;
    }
};