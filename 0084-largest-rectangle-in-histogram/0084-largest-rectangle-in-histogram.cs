public class Solution {
    public int LargestRectangleArea(int[] heights) {
        int n = heights.Length;
        Stack<int> stack = new Stack<int>();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (stack.Count > 0 && h < heights[stack.Peek()]) {
                int height = heights[stack.Pop()];
                int width = (stack.Count == 0) ? i : i - stack.Peek() - 1;
                maxArea = Math.Max(maxArea, height * width);
            }
            stack.Push(i);
        }

        return maxArea;
    }
}
