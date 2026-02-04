public class Solution
{
    public int MaxFrequency(int[] nums, int k)
    {
        int baseK = 0;
        foreach (int num in nums)
            if (num == k) baseK++;

        int bestGain = 0;

        for (int v = 1; v <= 50; v++)
        {
            if (v == k) continue;

            int curr = 0;
            int best = 0;

            foreach (int num in nums)
            {
                int w = 0;
                if (num == v) w = 1;
                else if (num == k) w = -1;

                curr = Math.Max(0, curr + w);
                best = Math.Max(best, curr);
            }

            bestGain = Math.Max(bestGain, best);
        }

        return baseK + bestGain;
    }
}
