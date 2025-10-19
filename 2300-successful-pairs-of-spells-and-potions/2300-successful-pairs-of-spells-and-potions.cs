public class Solution
{
    public int[] SuccessfulPairs(int[] spells, int[] potions, long success)
    {
        int n = spells.Length;
        Array.Sort(potions);
        int m = potions.Length;

        int[] res = new int[n];

        for (int i = 0; i < n; i++)
        {
            long spell = spells[i];
            int left = 0, right = m - 1;
            int firstSuccessIndex = m; // افترض مفيش ولا potion ناجح

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (spell * potions[mid] >= success)
                {
                    firstSuccessIndex = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            res[i] = m - firstSuccessIndex;
        }

        return res;
    }
}
