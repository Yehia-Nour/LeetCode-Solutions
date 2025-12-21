public class Solution
{
    private int[,,] _memory;
    private int _n;
    private int[] _nums;

    private int DP(int index, int count, int mod)
    {
        if (count == 3)
            return mod == 0 ? 0 : int.MinValue;

        if (index == _n)
            return int.MinValue;

        if (_memory[index, count, mod] != -1)
            return _memory[index, count, mod];

        int pick = DP(index + 1, count + 1, (mod + _nums[index]) % 3);
        if (pick != int.MinValue) pick += _nums[index];

        int skip = DP(index + 1, count, mod);

        _memory[index, count, mod] = Math.Max(pick, skip);
        return _memory[index, count, mod];
    }

    public int MaximumSum(int[] nums)
    {
        _nums = nums;
        _n = nums.Length;
        _memory = new int[_n, 4, 3]; 

        for (int i = 0; i < _n; i++)
            for (int j = 0; j <= 3; j++)
                for (int k = 0; k < 3; k++)
                    _memory[i, j, k] = -1;

        int result = DP(0, 0, 0);
        return result == int.MinValue ? 0 : result;
    }
}
