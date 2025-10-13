public class Solution
{
    int count = 0;
    int maxOr = 0;

    void Backtrack(int[] nums, int index, int currentOr)
    {
        if (index == nums.Length)
        {
            if (currentOr == maxOr)
                count++;
            return;
        }

        Backtrack(nums, index + 1, currentOr | nums[index]);

        Backtrack(nums, index + 1, currentOr);
    }

    public int CountMaxOrSubsets(int[] nums)
    {
        foreach (int num in nums)
            maxOr |= num;

        Backtrack(nums, 0, 0);

        return count;
    }
}
