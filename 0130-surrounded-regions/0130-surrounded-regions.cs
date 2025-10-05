public class Solution
{
    int[] dr = { -1, 0, 1, 0 };
    int[] dc = { 0, 1, 0, -1 };
    bool _isEdge = false;

    bool Isvalid(int r, int c, char[][] grid)
    {
        return r >= 0 && r < grid.Length && c >= 0 && c < grid[0].Length;
    }

    void DFS(int r, int c, char[][] grid, bool[][] visited, List<(int, int)> region)
    {
        if (!Isvalid(r, c, grid) || visited[r][c] || grid[r][c] == 'X')
            return;

        visited[r][c] = true;
        region.Add((r, c));

        // لو الخلية على الحافة
        if (r == 0 || r == grid.Length - 1 || c == 0 || c == grid[0].Length - 1)
            _isEdge = true;

        for (int d = 0; d < 4; ++d)
        {
            int nr = r + dr[d], nc = c + dc[d];
            DFS(nr, nc, grid, visited, region);
        }
    }

    public void Solve(char[][] board)
    {
        if (board == null || board.Length == 0)
            return;

        int m = board.Length;
        int n = board[0].Length;

        bool[][] visited = new bool[m][];
        for (int i = 0; i < m; ++i)
            visited[i] = new bool[n];

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (board[r][c] == 'O' && !visited[r][c])
                {
                    _isEdge = false;
                    List<(int, int)> region = new List<(int, int)>();

                    DFS(r, c, board, visited, region);

                    if (!_isEdge)
                    {
                        // المنطقة دي محاصرة → نغيرها كلها لـ X
                        foreach (var (rr, cc) in region)
                            board[rr][cc] = 'X';
                    }
                }
            }
        }
    }
}
