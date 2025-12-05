public class Solution
{
    public int TotalSteps(int[] nums)
    {
        int n = nums.Length;
        int[] dp = new int[n];
        Stack<int> stc = [];
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int maxSteps = 0;
            while (stc.Any() && nums[stc.Peek()] <= nums[i])
                maxSteps = int.Max(maxSteps, dp[stc.Pop()]);

            if (stc.Any())
                dp[i] = maxSteps + 1;

            stc.Push(i);
            ans = int.Max(ans, dp[i]);
        }

        return ans;
    }
}