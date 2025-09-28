public class Solution
{
    public int[] TransformArray(int[] nums)
    {
        int n = nums.Length;
        int evenCount = 0;
        foreach (int x in nums)
            if (x % 2 == 0) evenCount++;

        int[] ans = new int[n];
        for (int i = 0; i < evenCount; i++)
            ans[i] = 0;
        for (int i = evenCount; i < n; i++)
            ans[i] = 1;

        return ans;
    }
}