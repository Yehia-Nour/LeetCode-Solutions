    public class Solution
    {
        int[] dr = { -1, 0, 1, 0 };
        int[] dc = { 0, 1, 0, -1 };
        bool isvalid(int r, int c,  int[][] grid)
        {
            if (r < 0 || r >= grid.Length)
                return false;
            if (c < 0 || c >= grid[0].Length)
                return false;
            return true;
        }
        int dfs(int r, int c,  int[][] grid,  bool[,] visited)
        {
            if (!isvalid(r, c,  grid) || grid[r][c] == 0 || visited[r, c])
                return 0;

            visited[r,c] = true;
            int sum = grid[r][c];

            for (int d = 0; d < 4; ++d)
            {
                int nr = r + dr[d], nc = c + dc[d];
                sum += dfs(nr, nc,  grid,  visited);
            }
            return sum;
        }
        public int FindMaxFish(int[][] grid)
        {
            int r = grid.Length;
            int c = grid[0].Length;

            bool[,] visited = new bool[r, c];

            int max = 0;

            for(int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; j++)
                {
                    if (!visited[i, j] && grid[i][j] > 0)
                        max = int.Max(max, dfs(i, j, grid, visited));
                }
            }

            return max;
        }
    }