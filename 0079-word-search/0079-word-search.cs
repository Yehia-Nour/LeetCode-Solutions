public class Solution
{
    public bool Exist(char[][] board, string word)
    {
        int m = board.Length;
        int n = board[0].Length;

        bool Dfs(int i, int j, int idx)
        {
            if (idx == word.Length) return true;

            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
                return false;

            char temp = board[i][j];
            board[i][j] = '#'; 

            bool found =
                Dfs(i + 1, j, idx + 1) ||
                Dfs(i - 1, j, idx + 1) ||
                Dfs(i, j + 1, idx + 1) ||
                Dfs(i, j - 1, idx + 1);

            board[i][j] = temp;

            return found;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Dfs(i, j, 0))
                    return true;
            }
        }

        return false;
    }
}
