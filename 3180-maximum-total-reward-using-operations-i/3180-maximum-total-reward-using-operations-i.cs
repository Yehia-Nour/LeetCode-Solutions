public class Solution
{
    int?[,] _memory = default!;
    int[] _rewardValues = default!;
    int _n;

    int DP(int i, int sum)
    {
        if (i == _n)
            return sum;

        if (_memory[i, sum] is not null)
            return _memory[i, sum].Value;

        int take = sum;
        if (_rewardValues[i] > sum)
            take = DP(i + 1, sum + _rewardValues[i]);

        int skip = DP(i + 1, sum);

        int best = int.Max(take, skip);
        _memory[i, sum] = best;
        return best;
    }

    public int MaxTotalReward(int[] rewardValues)
    {
        Array.Sort(rewardValues);

        _rewardValues = rewardValues;
        _n = rewardValues.Length;

        _memory = new int?[_n + 1, 4000];

        return DP(0, 0);
    }
}