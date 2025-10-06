public class Solution
{
    int[] _nums;
    int[,] _memory;

    int[] Dp(int i)
    {
        if (i == _nums.Length - 1)
            return new int[] { _nums[i], _nums[i] };

        if (_memory[i, 0] != int.MaxValue)
            return new int[] { _memory[i, 0], _memory[i, 1] };

        int[] next = Dp(i + 1);
        int current = _nums[i];

        int maxVal = Math.Max(current, Math.Max(current * next[0], current * next[1]));
        int minVal = Math.Min(current, Math.Min(current * next[0], current * next[1]));

        _memory[i, 0] = maxVal;
        _memory[i, 1] = minVal;

        return new int[] { maxVal, minVal };
    }

    public int MaxProduct(int[] nums)
    {
        _nums = nums;
        _memory = new int[nums.Length, 2];

        for (int i = 0; i < nums.Length; i++)
        {
            _memory[i, 0] = int.MaxValue;
            _memory[i, 1] = int.MaxValue;
        }

        int result = int.MinValue;

        for (int i = 0; i < nums.Length; i++)
        {
            int[] res = Dp(i);
            result = Math.Max(result, res[0]);
        }

        return result;
    }
}
