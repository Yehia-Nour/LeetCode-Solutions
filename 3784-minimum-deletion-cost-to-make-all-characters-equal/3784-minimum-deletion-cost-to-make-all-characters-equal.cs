public class Solution
{
    public long MinCost(string s, int[] cost)
    {
        Dictionary<char, long> pairs = new();

        for (int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            if (!pairs.ContainsKey(c))
                pairs[c] = cost[i];
            else
                pairs[c] += cost[i];
        }

        var maxHeap = new PriorityQueue<long, long>();

        foreach (var item in pairs)
            maxHeap.Enqueue(item.Value, -item.Value);

        maxHeap.Dequeue();

        long res = 0;
        while (maxHeap.Count > 0)
            res += maxHeap.Dequeue();

        return res;
    }
}
