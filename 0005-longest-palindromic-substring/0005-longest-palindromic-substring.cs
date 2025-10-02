public class Solution
{
    string _s;
    int[,] _memory;
    int _startIndex = 0;
    int _maxLength = 1;

    int Dp(int i, int j)
    {
        if (i >= j) return 1;

        if (_memory[i, j] != -1)
            return _memory[i, j];

        if (_s[i] == _s[j])
        {
            int inside = Dp(i + 1, j - 1);
            if (inside == 1)
            {
                int length = j - i + 1;
                if (length > _maxLength)
                {
                    _maxLength = length;
                    _startIndex = i;
                }
                return _memory[i, j] = 1;
            }
        }

        return _memory[i, j] = 0;
    }

    public string LongestPalindrome(string s)
    {
        _s = s;
        int n = s.Length;
        _memory = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                _memory[i, j] = -1;
        }


        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                Dp(i, j);
            }
        }

        return s.Substring(_startIndex, _maxLength);
    }
}