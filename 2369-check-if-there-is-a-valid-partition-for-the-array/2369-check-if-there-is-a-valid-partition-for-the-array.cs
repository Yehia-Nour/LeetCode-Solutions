public class Solution
{
    public bool ValidPartition(int[] nums)
    {
        int n = nums.Length;
        bool?[] memo = new bool?[n];

        return CanPartition(nums, 0, memo, n);
    }

    bool CanPartition(int[] nums, int i, bool?[] memo, int n)
    {
        if (i == n)
            return true;

        if (memo[i] != null)
            return memo[i].Value;

        bool isValid = false;

        if (i + 1 < n && nums[i] == nums[i + 1])
            isValid = CanPartition(nums, i + 2, memo, n);

        if (!isValid && i + 2 < n && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
            isValid = CanPartition(nums, i + 3, memo, n);

        if (!isValid && i + 2 < n && nums[i + 1] == nums[i] + 1 && nums[i + 2] == nums[i] + 2)
            isValid = CanPartition(nums, i + 3, memo, n);

        memo[i] = isValid;
        return isValid;
    }
}
