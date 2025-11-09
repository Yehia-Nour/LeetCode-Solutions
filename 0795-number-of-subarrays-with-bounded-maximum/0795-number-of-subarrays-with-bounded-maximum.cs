public class Solution
{
    public int NumSubarrayBoundedMax(int[] nums, int left, int right)
    {
        int result = 0;
        int lastInvalid = -1;
        int lastValid = -1;

        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] > right)
                lastInvalid = i;

            if (nums[i] >= left && nums[i] <= right)
                lastValid = i;

            if (lastValid > lastInvalid)
                result += lastValid - lastInvalid;
        }

        return result;
    }
}
