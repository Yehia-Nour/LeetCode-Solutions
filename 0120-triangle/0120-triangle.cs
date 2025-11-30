public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        for (int row = triangle.Count - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                int belowLeft = triangle[row + 1][col];
                int belowRight = triangle[row + 1][col + 1];
                triangle[row][col] += Math.Min(belowLeft, belowRight);
            }
        }
        return triangle[0][0];
    }
}