public class Solution
{
    public int HammingWeight(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return (n & 1) + HammingWeight(n >> 1);
    }
}