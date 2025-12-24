public class Solution
{
    public long NumberOfPairs(int[] nums1, int[] nums2, int k)
    {
        Dictionary<int, int> freq = [];

        for (int i = 0; i < nums2.Length; i++)
        {
            int val = nums2[i] * k;
            if (!freq.ContainsKey(val))
                freq[val] = 0;
            freq[val]++;
        }

        long count = 0;

        foreach (int x in nums1)
        {
            for (int d = 1; d * d <= x; d++)
            {
                if (x % d == 0)
                {
                    if (freq.ContainsKey(d))
                        count += freq[d];

                    int other = x / d;
                    if (other != d && freq.ContainsKey(other))
                        count += freq[other];
                }
            }
        }

        return count;
    }
}
