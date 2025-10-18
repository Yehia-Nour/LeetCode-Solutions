public class Solution {
    public int[] FindPeakGrid(int[][] mat) {
        int m = mat.Length;
        int n = mat[0].Length;
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxRow = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int leftValue = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightValue = (mid + 1 < n) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftValue && mat[maxRow][mid] > rightValue) {
                return new int[] { maxRow, mid };
            } else if (mat[maxRow][mid] < rightValue) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return new int[] { -1, -1 };
    }
}
