public class Solution
{
    public bool CanReach(string s, int minJump, int maxJump)
    {
        int n = s.Length;
        if (s[n - 1] == '1') return false;

        bool[] dp = new bool[n];
        dp[0] = true;

        int reachableInWindow = 0;

        for (int i = 1; i < n; i++)
        {
            int addIndex = i - minJump;
            if (addIndex >= 0 && dp[addIndex]) reachableInWindow++;

            int removeIndex = i - maxJump - 1;
            if (removeIndex >= 0 && dp[removeIndex]) reachableInWindow--;

            if (s[i] == '0' && reachableInWindow > 0)
                dp[i] = true;
        }

        return dp[n - 1];
    }
}