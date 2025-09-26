public class Solution
{
    int _res = 0;
    string _str;
    int _n;

    void Backtrack(int count, bool[] used)
    {
        for (int i = 0; i < _n; i++)
        {
            if (used[i])
                continue;

            if (i > 0 && _str[i] == _str[i - 1] && !used[i - 1])
                continue;

            used[i] = true;

            _res++;

            Backtrack(count + 1, used);

            used[i] = false;
        }
    }

    public int NumTilePossibilities(string tiles)
    {
        char[] chars = tiles.ToCharArray();
        Array.Sort(chars);
        _str = new string(chars);
        _n = tiles.Length;

        bool[] used = new bool[_n];
        Backtrack(0, used);

        return _res;
    }
}
