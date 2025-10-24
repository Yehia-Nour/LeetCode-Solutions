public class Solution
{
    IList<IList<int>> _solutions = [];
    int _k;
    int _n;

    void BackTracking(int idx, List<int> solution, int sum)
    {
        if (sum > _n || solution.Count > _k)
            return;

        if (sum == _n && solution.Count == _k)
        {
            _solutions.Add(new List<int>(solution));
            return;
        }

        for (int i = idx; i <= 9; i++)
        {
            solution.Add(i);
            BackTracking(i + 1, solution, sum + i);
            solution.RemoveAt(solution.Count - 1);
        }
    }

    public IList<IList<int>> CombinationSum3(int k, int n)
    {
        _k = k;
        _n = n;

        BackTracking(1, [], 0);

        return _solutions;
    }
}
