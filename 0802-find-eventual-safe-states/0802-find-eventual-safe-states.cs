public class Solution {
    public IList<int> EventualSafeNodes(int[][] graph) {
        int n = graph.Length;
        List<int>[] rev = new List<int>[n];
        for (int i = 0; i < n; i++) rev[i] = new List<int>();

        int[] outdeg = new int[n];
        for (int i = 0; i < n; i++) {
            outdeg[i] = graph[i].Length;
            foreach (int j in graph[i]) {
                rev[j].Add(i); 
            }
        }

        Queue<int> q = new Queue<int>();
        for (int i = 0; i < n; i++) if (outdeg[i] == 0) q.Enqueue(i);

        List<int> safe = new List<int>();
        while (q.Count > 0) {
            int node = q.Dequeue();
            safe.Add(node);
            foreach (int prev in rev[node]) {
                outdeg[prev]--; 
                if (outdeg[prev] == 0) q.Enqueue(prev);
            }
        }

        safe.Sort(); 
        return safe;
    }
}
