public class Solution
{
    public int MaximumProduct(int[] nums, int k)
    {
        const long MOD = 1_000_000_007;

        var pq = new PriorityQueue<int, int>();

        foreach (var x in nums)
            pq.Enqueue(x, x);

        while (k-- > 0)
        {
            int min = pq.Dequeue();
            min++;
            pq.Enqueue(min, min);
        }

        long product = 1;
        while (pq.Count > 0)
            product = (product * pq.Dequeue()) % MOD;

        return (int)product;
    }
}
