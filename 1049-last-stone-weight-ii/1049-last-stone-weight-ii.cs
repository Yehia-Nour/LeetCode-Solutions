public class Solution
{
    Dictionary<(int, int), int> memo = new();

    int DP(int i, int val, int[] st, int n)
    {
        
        if (i == n)
            return Math.Abs(val);

        var key = (i, val);
        if (memo.ContainsKey(key))
            return memo[key];

        int pos = DP(i + 1, val + st[i], st, n);
        int neg = DP(i + 1, val - st[i], st, n);

        int result = Math.Min(pos, neg);
        memo[key] = result;
        return result;
    }

    public int LastStoneWeightII(int[] stones)
    {
        return DP(0, 0, stones, stones.Length);
    }
}
