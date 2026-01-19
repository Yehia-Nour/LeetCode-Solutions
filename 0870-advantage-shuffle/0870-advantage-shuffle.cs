public class Solution
{
    public int[] AdvantageCount(int[] nums1, int[] nums2)
    {
        int n = nums1.Length;
        var arr = new (int val, int ind)[n];

        for (int i = 0; i < n; i++)
            arr[i] = (nums2[i], i);

        Array.Sort(nums1);
        Array.Sort(arr, (a, b) => a.val.CompareTo(b.val));

        int left = 0, right = n - 1;
        int[] res = new int[n];

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums1[right] > arr[i].val)
                res[arr[i].ind] = nums1[right--];
            else
                res[arr[i].ind] = nums1[left++];
        }

        return res;
    }
}