public class Solution
{
    IList<IList<int>> _res = new List<IList<int>>();
    int[] _cands;
    void Backtrack(int idx, int target, List<int> path)
    {
        if (target == 0)
        {
            _res.Add(new List<int>(path));
            return;
        }

        if (target < 0 || idx == _cands.Length)
            return;

        path.Add(_cands[idx]);
        Backtrack(idx, target - _cands[idx], path);
        path.RemoveAt(path.Count - 1);

        Backtrack(idx + 1, target, path);
    }

    public IList<IList<int>> CombinationSum(int[] candidates, int target)
    {
        _cands = candidates;
        List<int> path = new List<int>();
        Backtrack(0, target, path);

        return _res;
    }
}