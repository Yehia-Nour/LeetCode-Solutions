public class Solution
{
    int[] nums;
    int n;
    int sum;
    int[] memo;

    public int MaxRotateFunction(int[] nums)
    {
        this.nums = nums;
        n = nums.Length;

        sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        memo = new int[n];
        Array.Fill(memo, int.MinValue);

        int max = int.MinValue;

        for (int k = 0; k < n; k++)
        {
            max = Math.Max(max, Solve(k));
        }

        return max;
    }

    int Solve(int k)
    {
        if (memo[k] != int.MinValue)
            return memo[k];

        if (k == 0)
        {
            int f0 = 0;
            for (int i = 0; i < n; i++)
                f0 += i * nums[i];

            memo[0] = f0;
            return f0;
        }

        memo[k] = Solve(k - 1) + sum - n * nums[n - k];
        return memo[k];
    }
}