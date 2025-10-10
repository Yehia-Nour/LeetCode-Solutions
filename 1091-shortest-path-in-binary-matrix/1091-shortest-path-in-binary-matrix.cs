struct Node
{
    public int r, c;
    public Node(int r, int c)
    {
        this.r = r;
        this.c = c;
    }
}

public class Solution
{
    int[] _dr = { -1, -1, -1, 0, 1, 0, 1, 1 };
    int[] _dc = { -1, 0, 1, 1, 0, -1, -1, 1 };

    bool IsValid(int r, int c, int[][] grid)
    {
        return r >= 0 && c >= 0 && r < grid.Length && c < grid[0].Length;
    }

    public int ShortestPathBinaryMatrix(int[][] grid)
    {
        int n = grid.Length;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        Queue<Node> q = new Queue<Node>();
        bool[,] visited = new bool[n, n];
        q.Enqueue(new Node(0, 0));
        visited[0, 0] = true;

        int level = 1;

        while (q.Count > 0)
        {
            int size = q.Count;
            for (int i = 0; i < size; i++)
            {
                Node curr = q.Dequeue();

                if (curr.r == n - 1 && curr.c == n - 1)
                    return level;

                for (int d = 0; d < 8; d++)
                {
                    int nr = curr.r + _dr[d];
                    int nc = curr.c + _dc[d];

                    if (IsValid(nr, nc, grid) && grid[nr][nc] == 0 && !visited[nr, nc])
                    {
                        visited[nr, nc] = true;
                        q.Enqueue(new Node(nr, nc));
                    }
                }
            }

            level++;
        }

        return -1;
    }
}
