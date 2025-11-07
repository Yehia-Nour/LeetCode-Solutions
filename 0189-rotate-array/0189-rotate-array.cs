public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        int n = nums.Length;
        int _k = k % n;
        int rotate = n - _k;

        Stack<int> stc = new Stack<int>();

        for (int i = rotate; i < n; i++)
            stc.Push(nums[i]);

        for (int i = 0; i < rotate; i++)
            stc.Push(nums[i]);

        for (int i = n - 1; i >= 0; i--)
            nums[i] = stc.Pop();
    }
}