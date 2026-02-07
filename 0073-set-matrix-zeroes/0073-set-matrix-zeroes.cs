public class Solution
{
    public void SetZeroes(int[][] matrix)
    {
        int rows = matrix.Length;
        int cols = matrix[0].Length;

        bool firstRowZero = false;
        bool firstColZero = false;

        for (int j = 0; j < cols; j++)
            if (matrix[0][j] == 0) { firstRowZero = true; break; }

        for (int i = 0; i < rows; i++)
            if (matrix[i][0] == 0) { firstColZero = true; break; }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (firstRowZero)
            for (int j = 0; j < cols; j++) matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
}
