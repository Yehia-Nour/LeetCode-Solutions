public class Solution {
    public int MinimumTime(int n, int[][] relations, int[] time) 
    {
        var graph = new List<int>[n + 1];
        for (int i = 1; i <= n; i++)
            graph[i] = new List<int>();

        var indegree = new int[n + 1];
        foreach (var r in relations) 
        {
            int prev = r[0], next = r[1];
            graph[prev].Add(next);
            indegree[next]++;
        }

        int[] dp = new int[n + 1];

        var queue = new Queue<int>();
        for (int i = 1; i <= n; i++) 
        {
            if (indegree[i] == 0) 
            {
                dp[i] = time[i - 1];
                queue.Enqueue(i);
            }
        }

        while (queue.Count > 0) 
        {
            int course = queue.Dequeue();
            foreach (var next in graph[course]) 
            {
                dp[next] = int.Max(dp[next], dp[course] + time[next - 1]);
                if (--indegree[next] == 0)
                    queue.Enqueue(next);
            }
        }

        return dp.Max();
    }
}
