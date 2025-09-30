public class Solution
{

    int CountInRange(int[] nums, int num, int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] == num)
                count++;
        }
        return count;
    }

    private int MajorityElementRec(int[] nums, int left, int right)
    {
        if (left == right)
            return nums[left];

        int mid = (left + right) / 2;

        int leftMajor = MajorityElementRec(nums, left, mid);

        int rightMajor = MajorityElementRec(nums, mid + 1, right);

        if (leftMajor == rightMajor)
            return leftMajor;

        int leftCount = CountInRange(nums, leftMajor, left, right);
        int rightCount = CountInRange(nums, rightMajor, left, right);

        return leftCount > rightCount ? leftMajor : rightMajor;
    }
    public int MajorityElement(int[] nums)
    {
        return MajorityElementRec(nums, 0, nums.Length - 1);
    }
}
