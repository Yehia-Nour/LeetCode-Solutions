public class Solution
{
    IList<IList<int>> _res = new List<IList<int>>();
    int[] _nums;
    int _n;
    void Backtrack(List<int> perm, bool[] used)
    {
        if (perm.Count == _n)
        {
            _res.Add(new List<int>(perm));
            return;
        }

        for (int i = 0; i < _n; i++)
        {
            if (used[i]) 
                continue;

            if (i > 0 && _nums[i] == _nums[i - 1] && !used[i - 1])
                continue;


            used[i] = true;
            perm.Add(_nums[i]);

            Backtrack(perm, used);

            perm.RemoveAt(perm.Count - 1);
            used[i] = false;
        }
    }

    public IList<IList<int>> PermuteUnique(int[] nums)
    {
        Array.Sort(nums);
        _nums = nums;
        _n = nums.Length;
        bool[] used = new bool[_n];
        Backtrack(new List<int>(), used);
        return _res;
    }
}
