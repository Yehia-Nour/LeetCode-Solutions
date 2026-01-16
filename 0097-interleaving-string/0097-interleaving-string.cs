public class Solution
{
    string _s1, _s2, _s3;
    bool?[,] _memo;

    public bool IsInterleave(string s1, string s2, string s3)
    {
        if (s1.Length + s2.Length != s3.Length)
            return false;

        _s1 = s1;
        _s2 = s2;
        _s3 = s3;

        _memo = new bool?[s1.Length + 1, s2.Length + 1];

        return Dfs(0, 0);
    }

    bool Dfs(int i, int j)
    {
        if (_memo[i, j] != null)
            return _memo[i, j].Value;

        if (i == _s1.Length && j == _s2.Length)
            return (bool)(_memo[i, j] = true);

        int k = i + j;

        bool result = false;

        if (i < _s1.Length && _s1[i] == _s3[k])
            result = Dfs(i + 1, j);

        if (!result && j < _s2.Length && _s2[j] == _s3[k])
            result = Dfs(i, j + 1);

        _memo[i, j] = result;
        return result;
    }
}