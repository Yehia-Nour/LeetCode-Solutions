public class Solution
{
    public int MinScore(int n, int[][] roads)
    {
        var graph = new List<(int to, int dist)>[n + 1];
        for (int i = 1; i <= n; i++)
            graph[i] = new List<(int, int)>();

        foreach (var r in roads)
        {
            int a = r[0], b = r[1], d = r[2];
            graph[a].Add((b, d));
            graph[b].Add((a, d));
        }

        var visited = new bool[n + 1];
        var q = new Queue<int>();
        q.Enqueue(1);
        visited[1] = true;

        int answer = int.MaxValue;

        while (q.Count > 0)
        {
            int u = q.Dequeue();

            foreach (var (v, d) in graph[u])
            {
                if (d < answer) answer = d;

                if (!visited[v])
                {
                    visited[v] = true;
                    q.Enqueue(v);
                }
            }
        }

        return answer;
    }
}