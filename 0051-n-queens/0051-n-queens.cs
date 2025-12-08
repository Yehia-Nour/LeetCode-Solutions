public class Solution
{
    int _n;
    List<bool> _antiDiag, _normDiag, _columns;
    List<StringBuilder> _emptyGrid;
    IList<IList<string>> _solutions = new List<IList<string>>();
    public IList<IList<string>> SolveNQueens(int n)
    {
        _n = n;
        _columns = Enumerable.Repeat(false, n).ToList();
        _antiDiag = Enumerable.Repeat(false, 2 * n - 1).ToList();
        _normDiag = Enumerable.Repeat(false, 2 * n - 1).ToList();
        _emptyGrid = new List<StringBuilder>();
        for (int i = 0; i < n; i++)
            _emptyGrid.Add(new StringBuilder(new string('.', n)));

        BackTrack(0);
        return _solutions;
    }

    void BackTrack(int r)
    {
        if (r == _n)
        {
            _solutions.Add(_emptyGrid.Select(r => r.ToString()).ToList());
            return;
        }

        for(int c = 0; c < _n; c++)
        {
            int x = r + c;
            int y = _n - 1 + r - c;

            if (_antiDiag[x] || _normDiag[y] || _columns[c])
                continue;


            _emptyGrid[r][c] = 'Q';
            _antiDiag[x] = true; _normDiag[y] = true; _columns[c] = true;

            BackTrack(r + 1);

            _emptyGrid[r][c] = '.';
            _antiDiag[x] = false; _normDiag[y] = false; _columns[c] = false;
        }
    }
}