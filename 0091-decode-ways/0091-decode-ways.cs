    public class Solution
    {
        string _s;
        int[] _memory;
        bool Can2Digits(int i)
        {
            if (i + 1 >= _s.Length)
                return false;

            if (_s[i] == '1')
                return true;

            return _s[i] == '2' && _s[i + 1] <= '6';
        }
        int dp(int i)
        {
            if (i == _s.Length)
                return 1;

            if (_s[i] == '0')
                return 0;

            if (_memory[i] != -1)
                return _memory[i];

            _memory[i] = dp(i + 1);
            if (Can2Digits(i))
                _memory[i] += dp(i + 2);

            return _memory[i];

        }

        public int NumDecodings(string s)
        {
            _s = s;
            _memory = new int[_s.Length];

            Array.Fill(_memory, -1);
            return dp(0);
        }
    }