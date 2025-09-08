public class Solution
{
    const int MOD = 1000000007;
    const int MAX = 50 + 1;

    int[,,] _memory;
    int _rows, _cols, _maxMoves;

    int dp(int r, int c, int move)
    {
        if (move > _maxMoves)
            return 0;

        if (r < 0 || r >= _rows || c < 0 || c >= _cols)
            return 1;

        if (_memory[r, c, move] != -1)
            return _memory[r, c, move];

        long result = 0;

        result += dp(r, c - 1, move + 1); result %= MOD;
        result += dp(r, c + 1, move + 1); result %= MOD;
        result += dp(r + 1, c, move + 1); result %= MOD;
        result += dp(r - 1, c, move + 1); result %= MOD;

        return _memory[r, c, move] = (int)result;
    }

    public int FindPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        _rows = m;
        _cols = n;
        _maxMoves = maxMove;

        _memory = new int[MAX, MAX, MAX];

        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                for (int k = 0; k < MAX; k++)
                    _memory[i, j, k] = -1;

        return dp(startRow, startColumn, 0);
    }
}
