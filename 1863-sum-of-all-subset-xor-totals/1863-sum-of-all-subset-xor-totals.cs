public class Solution
{
    int _total; 
    int[] _nums;
    int _n;

    void Dfs(int idx, int curXor)
    {
        if (idx == _n)
        {
            _total += curXor; 
            return;
        }

        Dfs(idx + 1, curXor);

        Dfs(idx + 1, curXor ^ _nums[idx]);
    }

    public int SubsetXORSum(int[] nums)
    {
        _nums = nums;
        _n = nums.Length;
        _total = 0; 

        Dfs(0, 0); 

        return _total;
    }
}
