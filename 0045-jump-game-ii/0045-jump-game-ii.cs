public class Solution
{
    int _n;
    int[] _nums;
    int[] _memory;

    int DP(int start)
    {
        if (start == _n - 1)
            return 0;

        if (start >= _n)
            return int.MaxValue;

        if (_memory[start] != -1)
            return _memory[start];

        int min = int.MaxValue;

        for (int jump = 1; jump <= _nums[start]; jump++)
        {
            int next = DP(start + jump);

            if (next != int.MaxValue)
                min = Math.Min(min, next + 1);
        }

        _memory[start] = min;
        return min;
    }

    public int Jump(int[] nums)
    {
        _nums = nums;
        _n = nums.Length;
        _memory = new int[_n];

        Array.Fill(_memory, -1);

        return DP(0);
    }
}
