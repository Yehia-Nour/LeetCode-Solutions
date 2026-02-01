public class Solution
{
    public int MinimumCost(int[] nums)
    {
        int n = nums.Length;
        int ans = int.MaxValue;

        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                int cost = nums[0] + nums[i] + nums[j];
                if (cost < ans) 
                    ans = cost;
            }
        }

        return ans;
    }
}
