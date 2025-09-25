public class Solution
{
    IList<IList<int>> _res = new List<IList<int>>();
    int[] _nums;
    int _target;
    int _n;

    void Backtrack(List<int> comb, int start, int remain)
    {
        if (remain == 0)
        {
            _res.Add(new List<int>(comb));
            return;
        }

        for (int i = start; i < _n; i++)
        {
            if (_nums[i] > remain) break;

            if (i > start && _nums[i] == _nums[i - 1]) continue;

            comb.Add(_nums[i]);
            Backtrack(comb, i + 1, remain - _nums[i]);
            comb.RemoveAt(comb.Count - 1);
        }
    }

    public IList<IList<int>> CombinationSum2(int[] candidates, int target)
    {
        Array.Sort(candidates);
        _nums = candidates;
        _target = target;
        _n = candidates.Length;

        Backtrack(new List<int>(), 0, target);
        return _res;
    }
}
