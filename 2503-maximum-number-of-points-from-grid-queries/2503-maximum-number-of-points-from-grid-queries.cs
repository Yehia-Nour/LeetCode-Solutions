using System.Collections.Generic;

public class Solution
{
    public int[] MaxPoints(int[][] grid, int[] queries)
    {
        int m = grid.Length, n = grid[0].Length;
        int k = queries.Length;
        int[] ans = new int[k];

        var qs = new (int value, int idx)[k];
        for (int i = 0; i < k; i++)
            qs[i] = (queries[i], i);
        Array.Sort(qs, (a, b) => a.value.CompareTo(b.value));

        bool[,] vis = new bool[m, n];
        vis[0, 0] = true;

        int[] dr = { -1, 0, 1, 0 };
        int[] dc = { 0, 1, 0, -1 };

        var pq = new PriorityQueue<(int r, int c), int>();
        pq.Enqueue((0, 0), grid[0][0]);

        int count = 0;

        foreach (var (q, idx) in qs)
        {
            while (pq.Count > 0)
            {
                var val = pq.Peek();
                int r = val.Item1;
                int c = val.Item2;
                int cellValue = grid[r][c];

                if (cellValue >= q)
                    break;

                pq.Dequeue();
                count++;

                for (int d = 0; d < 4; d++)
                {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    if (vis[nr, nc]) continue;

                    vis[nr, nc] = true;
                    pq.Enqueue((nr, nc), grid[nr][nc]);
                }
            }

            ans[idx] = count;
        }

        return ans;
    }
}
