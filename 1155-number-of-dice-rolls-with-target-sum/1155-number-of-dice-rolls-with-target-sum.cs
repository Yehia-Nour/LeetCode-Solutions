    public class Solution
    {
        const int MOD = 1_000_000_007;
        int[,] memory;
        int dices, faces;

        int CountCombs(int idx, int target)
        {
            if (target < 0)
                return 0;

            if (idx == dices && target == 0)
                return 1;

            if (idx == dices || target == 0)
                return 0;

            if (memory[idx, target] != -1)
                return memory[idx, target];

            long ret = 0;
            for (int f = 1; f <= faces; f++)
            {
                ret += CountCombs(idx + 1, target - f);
                ret %= MOD;
            }

            return memory[idx, target] = (int)ret;
        }

        public int NumRollsToTarget(int n, int k, int target)
        {
            dices = n;
            faces = k;
            memory = new int[n + 1, target + 1];

            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= target; j++)
                    memory[i, j] = -1;

            return CountCombs(0, target);
        }
    }