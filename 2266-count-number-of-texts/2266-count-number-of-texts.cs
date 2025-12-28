public class Solution {
    private const int MOD = 1_000_000_007;

    public int CountTexts(string pressedKeys) {
        int n = pressedKeys.Length;
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int maxPress = (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') ? 4 : 3;

            for (int j = 1; j <= maxPress; j++)
            {
                if (i - j >= 0)
                {
                    bool valid = true;
                    for (int k = 0; k < j; k++)
                    {
                        if (pressedKeys[i - 1] != pressedKeys[i - j + k])
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                        dp[i] = (dp[i] + dp[i - j]) % MOD;
                }
            }
        }

        return dp[n];
    }
}