public class Solution
{
    public int ChalkReplacer(int[] chalk, int k)
    {
        long total = 0;
        for (int i = 0; i < chalk.Length; i++)
            total += chalk[i];

        long rem = k % total;

        for (int i = 0; i < chalk.Length; i++)
        {
            if (rem < chalk[i])
                return i;
            rem -= chalk[i];
        }

        return 0;
    }
}
