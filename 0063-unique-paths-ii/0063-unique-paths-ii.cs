    public class Solution
    {
        int[,] _memory;
        int[][] _grid;

        int dp(int r, int c)
        {
            int rows = _grid.Length;
            int cols = _grid[0].Length;

            if (r >= rows || c >= cols || _grid[r][c] == 1)
                return 0;

            if (r == rows - 1 && c == cols - 1)
                return 1;

            if (_memory[r, c] != -1)
                return _memory[r, c];

            return _memory[r, c] = dp(r + 1, c) + dp(r, c + 1);
        }

        public int UniquePathsWithObstacles(int[][] obstacleGrid)
        {
            _grid = obstacleGrid;
            int rows = obstacleGrid.Length;
            int cols = obstacleGrid[0].Length;

            _memory = new int[rows, cols];

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    _memory[i, j] = -1;

            return dp(0,0);
        }
    }