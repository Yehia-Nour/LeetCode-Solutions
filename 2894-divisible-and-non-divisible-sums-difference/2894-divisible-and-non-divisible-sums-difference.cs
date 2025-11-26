public class Solution 
{
    public int DifferenceOfSums(int n, int m) 
    {
        int num1 = 0, num2 = 0;

        for (int i = 1; i <= n; i++)
            (i % m == 0 ? ref num2 : ref num1) += i;

        return num1 - num2;
    }
}
