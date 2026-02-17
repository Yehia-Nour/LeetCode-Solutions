public class Solution
{
    public long MinCost(string s, int[] cost)
    {
        long total = 0;
        long best = 0;

        Dictionary<char, long> sum = new();

        for (int i = 0; i < s.Length; i++)
        {
            total += cost[i];

            char c = s[i];
            if (!sum.ContainsKey(c)) sum[c] = 0;
            sum[c] += cost[i];

            if (sum[c] > best) best = sum[c];
        }

        return total - best;
    }
}