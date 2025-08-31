    public class Solution
    {
        const int _max = 500 + 1;
        int[,] _memory = new int[_max, _max];
        string _s;
        private int Min(int start, int end)
        {
            if (start >= end)
                return 0;

            if (_memory[start, end] != -1)
                return _memory[start, end];

            if (_s[start] == _s[end])
                return _memory[start, end] = Min(start + 1, end - 1);

            int choice1 = 1 + Min(start, end - 1);
            int choice2 = 1 + Min(start + 1, end);

            return _memory[start, end] = int.Min(choice1, choice2);
        }

        public int MinInsertions(string s)
        {
            for (int i = 0; i < _max; i++)
                for (int j = 0; j < _max; j++)
                    _memory[i, j] = -1;

            _s = s;
            return Min(0, s.Length - 1);
        }
    }