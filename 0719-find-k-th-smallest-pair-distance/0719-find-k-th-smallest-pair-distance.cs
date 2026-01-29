public class Solution
{
    public int SmallestDistancePair(int[] nums, int k)
    {
        Array.Sort(nums);

        int n = nums.Length;
        int low = 0;
        int high = nums[n - 1] - nums[0];

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int count = CountPairs(nums, mid);

            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }

    int CountPairs(int[] nums, int maxDist)
    {
        int count = 0;
        int left = 0;

        for (int right = 0; right < nums.Length; right++)
        {
            while (nums[right] - nums[left] > maxDist)
                left++;

            count += right - left;
        }

        return count;
    }
}