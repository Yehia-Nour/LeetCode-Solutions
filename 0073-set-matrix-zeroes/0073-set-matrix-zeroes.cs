public class Solution
{
    int[][] _matrix;
    int _rows;
    int _cols;

    void RowDFS(int i)
    {
        for(int col = 0; col < _cols; col++)
            _matrix[i][col] = 0;
    }

    void ColDFS(int j)
    {
        for(int row = 0; row < _rows; row++)
            _matrix[row][j] = 0;
    }

    public void SetZeroes(int[][] matrix)
    {
        _matrix = matrix;
        _rows = matrix.Length;
        _cols = matrix[0].Length;
        List<(int row, int col)> zeros = [];

        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
                if (matrix[i][j] == 0) zeros.Add((i, j));
        }

        HashSet<int> rowVisited = [];
        HashSet<int> colVisited = [];

        for(int i = 0; i < zeros.Count; ++i)
        {
            if (!rowVisited.Contains(zeros[i].row))
            {
                rowVisited.Add(zeros[i].row);
                RowDFS(zeros[i].row);
            }
            if (!colVisited.Contains(zeros[i].col))
            {
                colVisited.Add(zeros[i].col);
                ColDFS(zeros[i].col);
            }
        }
    }
}