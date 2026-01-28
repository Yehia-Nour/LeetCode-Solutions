public class Solution
{
    const int MOD = 1_000_000_007;

    public int CountPathsWithXorValue(int[][] grid, int k)
    {
        int m = grid.Length;
        int n = grid[0].Length;

        int[][] dp = new int[n][];
        for (int j = 0; j < n; j++)
            dp[j] = new int[16];

        dp[0][grid[0][0]] = 1;

        for (int j = 1; j < n; j++)
        {
            int val = grid[0][j];
            for (int x = 0; x < 16; x++)
            {
                int ways = dp[j - 1][x];
                if (ways == 0) continue;
                dp[j][x ^ val] = (dp[j][x ^ val] + ways) % MOD;
            }
        }

        for (int i = 1; i < m; i++)
        {
            {
                int val = grid[i][0];
                int[] newCol = new int[16];
                for (int x = 0; x < 16; x++)
                {
                    int waysFromTop = dp[0][x];
                    if (waysFromTop == 0) continue;
                    newCol[x ^ val] = (newCol[x ^ val] + waysFromTop) % MOD;
                }
                dp[0] = newCol;
            }

            for (int j = 1; j < n; j++)
            {
                int val = grid[i][j];
                int[] newState = new int[16];

                for (int x = 0; x < 16; x++)
                {
                    int fromTop = dp[j][x];
                    if (fromTop != 0)
                        newState[x ^ val] = (newState[x ^ val] + fromTop) % MOD;

                    int fromLeft = dp[j - 1][x];
                    if (fromLeft != 0)
                        newState[x ^ val] = (newState[x ^ val] + fromLeft) % MOD;
                }

                dp[j] = newState;
            }
        }

        return dp[n - 1][k];
    }
}