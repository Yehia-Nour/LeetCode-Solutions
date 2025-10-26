public class Solution
{
    int[] _nums = null!;
    int _n;
    int?[,] _memo;

    int Dp(int i, bool prevTaken, bool firstTaken)
    {
        if (i >= _n)
            return 0;

        int state = (prevTaken ? 1 : 0) + (firstTaken ? 2 : 0);

        if (_memo[i, state].HasValue)
            return _memo[i, state].Value;

        int take = 0;
        int skip = 0;

        if (!prevTaken)
        {
            if (!(i == _n - 1 && firstTaken))
            {
                bool nextFirstTaken = firstTaken || (i == 0);
                take = _nums[i] + Dp(i + 1, true, nextFirstTaken);
            }
        }

        skip = Dp(i + 1, false, firstTaken);

        int ans = Math.Max(take, skip);
        _memo[i, state] = ans;
        return ans;
    }

    public int Rob(int[] nums)
    {
        _nums = nums;
        _n = nums.Length;

        if (_n == 1)
            return nums[0];
        if (_n == 2)
            return Math.Max(nums[0], nums[1]);

        _memo = new int?[_n, 4];

        int case1 = _nums[0] + Dp(1, true, true);

        int case2 = Dp(0, false, false);

        return Math.Max(case1, case2);
    }
}
