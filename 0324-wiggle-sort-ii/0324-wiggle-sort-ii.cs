public class Solution {
    public void WiggleSort(int[] nums) {
        int n = nums.Length;
        int mid = FindKLargest(nums, (n + 1) / 2);

        int[] copy = (int[])nums.Clone();
        Array.Sort(copy);

        int left = (n - 1) / 2;
        int right = n - 1; 

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                nums[i] = copy[left--];
            else
                nums[i] = copy[right--]; 
        }
    }

    int FindKLargest(int[] nums, int k)
    {
        Array.Sort(nums);
        return nums[nums.Length - k];
    }
}