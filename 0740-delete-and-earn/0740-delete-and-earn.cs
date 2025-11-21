public class Solution
{
    int[] points;
    int[] memo;
    int maxVal;

    int Solve(int i)
    {
        if (i > maxVal)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int take = points[i] + Solve(i + 2);
        int skip = Solve(i + 1);

        memo[i] = Math.Max(take, skip);
        return memo[i];
    }

    public int DeleteAndEarn(int[] nums)
    {
        if (nums.Length == 0)
            return 0;

        maxVal = 0;
        foreach (int v in nums)
            if (v > maxVal) maxVal = v;

        points = new int[maxVal + 1];
        foreach (int v in nums)
            points[v] += v;

        memo = new int[maxVal + 1];
        Array.Fill(memo, -1);

        return Solve(0);
    }
}