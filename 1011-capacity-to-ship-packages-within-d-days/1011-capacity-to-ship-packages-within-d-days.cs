public class Solution
{
    int[] _weights;
    int _days;

    bool IsValid(int mid)
    {
        int daysNeeded = 1;
        int currentWeight = 0;

        foreach (var w in _weights)
        {
            if (currentWeight + w > mid)
            {
                daysNeeded++;
                currentWeight = 0;
            }
            currentWeight += w;
        }

        return daysNeeded <= _days;
    }

    public int ShipWithinDays(int[] weights, int days)
    {
        _weights = weights;
        _days = days;

        int start = weights.Max();
        int end = weights.Sum();
        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (IsValid(mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return ans;
    }
}
