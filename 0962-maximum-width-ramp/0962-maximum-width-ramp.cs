public class Solution {
    public int MaxWidthRamp(int[] nums)
    {
        int n = nums.Length;
        Stack<int> st = [];

        for (int i = 0; i < n; i++)
        {
            if (st.Count == 0 || nums[i] < nums[st.Peek()])
                st.Push(i);
        }

        int ans = 0;

        for (int j = n - 1; j >= 0; j--)
        {
            while (st.Count > 0 && nums[j] >= nums[st.Peek()])
            {
                int i = st.Pop();
                ans = int.Max(ans, j - i);
            }
        }

        return ans;
    }
}
