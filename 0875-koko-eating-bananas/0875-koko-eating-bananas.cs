public class Solution
{
    int[] _piles;
    long _h;

    bool IsValid(int mid)
    {
        long hours = 0;

        for (int i = 0; i < _piles.Length; i++)
        {
            hours += ( (long)_piles[i] + mid - 1 ) / mid;

            if (hours > _h) return false;
        }

        return hours <= _h;
    }

    public int MinEatingSpeed(int[] piles, int h)
    {
        _piles = piles;
        _h = h;
        int maxNumber = piles.Max();

        int start = 1, end = maxNumber, ans = maxNumber;

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
