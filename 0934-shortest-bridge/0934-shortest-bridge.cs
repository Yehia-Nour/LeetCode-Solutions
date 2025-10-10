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
    int[] _dr = { -1, 1, 0, 0 };
    int[] _dc = { 0, 0, -1, 1 };

    bool IsValid(int r, int c, int[][] grid)
    {
        return r >= 0 && c >= 0 && r < grid.Length && c < grid[0].Length;
    }

    void DFS(int r, int c, int[][] grid, Queue<Node> q)
    {
        if (!IsValid(r, c, grid) || grid[r][c] != 1)
            return;

        grid[r][c] = 2;
        q.Enqueue(new Node(r, c));

        for (int d = 0; d < 4; d++)
        {
            DFS(r + _dr[d], c + _dc[d], grid, q);
        }
    }

    public int ShortestBridge(int[][] grid)
    {
        int N = grid.Length;
        Queue<Node> q = new Queue<Node>();
        bool found = false;

        for (int i = 0; i < N && !found; i++)
        {
            for (int j = 0; j < N && !found; j++)
            {
                if (grid[i][j] == 1)
                {
                    DFS(i, j, grid, q);
                    found = true;
                }
            }
        }

        int level = 0;
        while (q.Count > 0)
        {
            int size = q.Count;

            for (int i = 0; i < size; i++)
            {
                Node node = q.Dequeue();

                for (int d = 0; d < 4; d++)
                {
                    int nr = node.r + _dr[d];
                    int nc = node.c + _dc[d];

                    if (!IsValid(nr, nc, grid))
                        continue;

                    if (grid[nr][nc] == 1)
                        return level;

                    if (grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 2;
                        q.Enqueue(new Node(nr, nc));
                    }
                }
            }

            level++;
        }

        return -1;
    }
}
