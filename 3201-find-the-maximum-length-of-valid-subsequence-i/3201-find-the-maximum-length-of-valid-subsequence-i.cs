    public class Solution
    {
        int[] _nums;
        int[,] _memory;

        private int dp(int i, bool expectEven)
        {
            if (i == _nums.Length)
                return 0;

            int parity = expectEven ? 1 : 0;

            if (_memory[i, parity] != -1)
                return _memory[i, parity];

            int choice1 = 0, choice2 = 0;

            if (expectEven)
            {
                if (_nums[i] % 2 == 1) 
                    choice1 = 1 + dp(i + 1, false);
                choice2 = dp(i + 1, true);
            }
            else
            {
                if (_nums[i] % 2 == 0) 
                    choice1 = 1 + dp(i + 1, true);
                choice2 = dp(i + 1, false);
            }

            return _memory[i, parity] = int.Max(choice1, choice2);
        }

        public int MaximumLength(int[] nums)
        {
            _nums = nums;
            _memory = new int[nums.Length, 2];

            for (int i = 0; i < nums.Length; i++)
                for (int j = 0; j < 2; j++)
                    _memory[i, j] = -1;

            int alternating = int.Max(dp(0, true), dp(0, false));

            int allEven = nums.Count(x => x % 2 == 0);

            int allOdd = nums.Count(x => x % 2 == 1);

            return int.Max(alternating, int.Max(allEven, allOdd));
        }
    }
