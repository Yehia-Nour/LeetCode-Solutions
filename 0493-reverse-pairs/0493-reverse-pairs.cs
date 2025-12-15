public class Solution {
    public int ReversePairs(int[] nums) {
      if (nums.Length == 0)  
            return 0;

        return (int)MergeSort(nums, 0, nums.Length - 1);
    }

    long MergeSort(int[] nums, int left, int right)
    {
        if (left >= right)
            return 0;

        
        int mid = left + (right - left) / 2;

        long count = 0;

        count += MergeSort(nums, left, mid);

        count += MergeSort(nums, mid + 1, right);

        count += CountPairs(nums, left, mid, right);

        Merge(nums, left, mid, right);

        return count;
    }

    long CountPairs(int[] nums, int left, int mid, int right)
    {
        long count = 0;
        int j = mid + 1;

        for (int i = left; i <= mid; i++)
        {
            while (j <= right && nums[i] > 2L * nums[j])
                j++;

            count += (j - (mid + 1));
        }

        return count;
    }

    void Merge(int[] nums, int left, int mid, int right)
    {
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= right)
            temp[k++] = nums[j++];

        for (int x = 0; x < temp.Length; x++)
            nums[left + x] = temp[x];
    }
}