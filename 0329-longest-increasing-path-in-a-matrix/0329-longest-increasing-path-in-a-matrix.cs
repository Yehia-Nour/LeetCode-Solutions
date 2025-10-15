public class Solution
{
    int[] _dr = { -1, 0, 1, 0 };
    int[] _dc = { 0, 1, 0, -1 };
    int[,] _memory;
    int[][] _matrix;
    int _rows, _cols;

    bool IsValid(int r, int c)
    {
        return r >= 0 && r < _rows && c >= 0 && c < _cols;
    }

    int DP(int r, int c)
    {
        if (_memory[r, c] != -1)
            return _memory[r, c];

        int best = 1;

        for (int d = 0; d < 4; ++d)
        {
            int nr = r + _dr[d];
            int nc = c + _dc[d];

            if (IsValid(nr, nc) && _matrix[nr][nc] > _matrix[r][c])
                best = int.Max(best, 1 + DP(nr, nc));
        }

        return _memory[r, c] = best;
    }

    public int LongestIncreasingPath(int[][] matrix)
    {
        _matrix = matrix;
        _rows = matrix.Length;
        _cols = matrix[0].Length;
        _memory = new int[_rows, _cols];

        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _memory[i, j] = -1;

        int ans = 0;

        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                ans = int.Max(ans, DP(i, j));

        return ans;
    }
}
