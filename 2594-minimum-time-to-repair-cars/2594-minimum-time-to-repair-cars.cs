public class Solution
{
    private bool CanRepair(long time, int[] ranks, int cars)
    {
        long total = 0;
        foreach (int r in ranks)
        {
            total += (long)Math.Sqrt((double)time / r);
            if (total >= cars)
                return true;
        }
        return total >= cars;
    }

    public long RepairCars(int[] ranks, int cars)
    {
        long left = 0, right = (long)1e18;

        while (left < right)
        {
            long mid = (left + right) / 2;

            if (CanRepair(mid, ranks, cars))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
