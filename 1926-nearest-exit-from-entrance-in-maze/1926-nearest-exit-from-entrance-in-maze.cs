public class Solution
{
    private int[] _dr = { -1, 0, 1, 0 };
    private int[] _dc = { 0, 1, 0, -1 };

    public int NearestExit(char[][] maze, int[] entrance)
    {
        int rows = maze.Length;
        int cols = maze[0].Length;

        bool[,] visited = new bool[rows, cols];
        Queue<(int r, int c, int steps)> queue = new();

        int startRow = entrance[0];
        int startCol = entrance[1];

        queue.Enqueue((startRow, startCol, 0));
        visited[startRow, startCol] = true;

        while (queue.Count > 0)
        {
            var (r, c, steps) = queue.Dequeue();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + _dr[i];
                int nc = c + _dc[i];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                if (maze[nr][nc] == '+' || visited[nr, nc])
                    continue;

                if (nr == 0 || nr == rows - 1 || nc == 0 || nc == cols - 1)
                    return steps + 1;

                visited[nr, nc] = true;
                queue.Enqueue((nr, nc, steps + 1));
            }
        }

        return -1;
    }
}
