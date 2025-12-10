public class Solution
{
    public int MinDeletion(int[] nums)
    {
        int deletions = 0;
        int i = 0;

        while (i < nums.Length - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                deletions++;
                i++;
            }
            else
                i += 2; 
        }

        if ((nums.Length - deletions) % 2 == 1)
            deletions++;

        return deletions;
    }
}
