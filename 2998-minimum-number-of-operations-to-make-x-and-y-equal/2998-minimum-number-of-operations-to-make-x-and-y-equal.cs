public class Solution
{
    public int MinimumOperationsToMakeEqual(int x, int y)
    {
        if (x == y) return 0;

        Queue<(int num, int steps)> q = new();
        HashSet<int> visited = new();

        q.Enqueue((x, 0));
        visited.Add(x);

        while (q.Count > 0)
        {
            var (cur, steps) = q.Dequeue();
            if (cur == y) return steps;

            List<int> next = new();

            if (cur % 11 == 0) next.Add(cur / 11);
            if (cur % 5 == 0) next.Add(cur / 5);
            next.Add(cur - 1);
            next.Add(cur + 1);

            foreach (var n in next)
            {
                if (n < 0 || n > 10000 || visited.Contains(n)) continue;
                visited.Add(n);
                q.Enqueue((n, steps + 1));
            }
        }

        return -1;
    }
}