public class Solution
{
    public int MinSetSize(int[] arr)
    {
        Dictionary<int, int> freq = [];
        foreach (int num in arr)
        {
            if (!freq.ContainsKey(num))
                freq[num] = 0;

            freq[num]++;
        }

        List<int> frequencies = freq.Values.ToList();
        frequencies.Sort((a, b) => b.CompareTo(a));

        int removed = 0;
        int half = arr.Length / 2;
        int setSize = 0;

        foreach (int count in frequencies)
        {
            removed += count;
            setSize++;

            if (removed >= half)
                break;
        }

        return setSize;
    }
}
