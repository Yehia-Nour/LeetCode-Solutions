public class Solution
{
    public int MaxUncrossedLines(int[] nums1, int[] nums2)
    {
        int n = nums1.Length, m = nums2.Length;
        int?[,] memo = new int?[n + 1, m + 1];

        int Dfs(int i, int j)
        {
            if (i == n || j == m) 
                return 0;

            if (memo[i, j].HasValue) 
                return memo[i, j].Value;

            int ans;
            if (nums1[i] == nums2[j])
                ans = 1 + Dfs(i + 1, j + 1);
            else
                ans = int.Max(Dfs(i + 1, j), Dfs(i, j + 1));

            memo[i, j] = ans;
            return ans;
        }

        return Dfs(0, 0);
    }
}
