public class Solution {
    bool CanSplit(int[] nums, int k, int maxAllowed)
    {
        int count = 1;
        int currentSum = 0;

        foreach(int num in nums)
        {
            if (currentSum + num <= maxAllowed)
                currentSum += num;
            else
            {
                count++;
                currentSum = num;

                if (count > k)
                    return false;
            }
        }

        return true;
    }
    public int SplitArray(int[] nums, int k) {
        int right = nums.Sum();
        int left = nums.Max();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (CanSplit(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}