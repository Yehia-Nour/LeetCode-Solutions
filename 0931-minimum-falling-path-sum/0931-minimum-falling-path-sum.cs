public class Solution
{
    public int MinFallingPathSum(int[][] matrix)
    {
        int rows = matrix.Length;
        int cols = matrix[0].Length;

        for (int r = rows - 2; r >= 0; r--)
        {
            for (int c = 0; c < cols; c++)
            {
                int down = matrix[r + 1][c];
                int downLeft = (c > 0) ? matrix[r + 1][c - 1] : int.MaxValue;
                int downRight = (c < cols - 1) ? matrix[r + 1][c + 1] : int.MaxValue;

                matrix[r][c] += Math.Min(down, Math.Min(downLeft, downRight));
            }
        }

        int min = int.MaxValue;
        for (int c = 0; c < cols; c++)
            min = Math.Min(min, matrix[0][c]);

        return min;
    }
}
