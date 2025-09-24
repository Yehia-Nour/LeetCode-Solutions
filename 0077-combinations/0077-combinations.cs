public class Solution
{
    IList<IList<int>> _res = new List<IList<int>>();
    int _n, _k;
    void Backtrack(int idx, List<int> combines)
    {
        if (combines.Count == _k)
        {
            _res.Add(new List<int>(combines));
            return;
        }

        for (int i = idx; i <= _n; i++)
        {
            combines.Add(i);
            Backtrack(i + 1, combines);
            combines.RemoveAt(combines.Count - 1);
        }
    }
    public IList<IList<int>> Combine(int n, int k)
    {
        _n = n;
        _k = k;
        List<int> combines = new List<int>();
        Backtrack(1, combines);

        return _res;
    }
}