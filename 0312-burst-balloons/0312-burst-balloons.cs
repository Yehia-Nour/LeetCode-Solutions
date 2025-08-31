    public class Solution
    {
        const int _max = 300 + 5;
        int[,] _memory = new int[_max, _max];
        int[] _nums;

        private int Brust(int start, int end)
        {
            if (start > end) return 0;

            if (_memory[start, end] != -1)
                return _memory[start, end];

            int best = 0;

            for (int i = start; i <= end; i++)
            {
                int coins = _nums[start - 1] * _nums[i] * _nums[end + 1];
                coins += Brust(start, i - 1) + Brust(i + 1, end);
                best = Math.Max(best, coins);
            }

            _memory[start, end] = best;
            return best;
        }

        public int MaxCoins(int[] nums)
        {
            _nums = new int[nums.Length + 2];
            _nums[0] = 1;
            _nums[nums.Length + 1] = 1;
            for (int i = 0; i < nums.Length; i++)
                _nums[i + 1] = nums[i];

            for (int i = 0; i < _max; i++)
                for (int j = 0; j < _max; j++)
                    _memory[i, j] = -1;

            return Brust(1, nums.Length);
        }
    }