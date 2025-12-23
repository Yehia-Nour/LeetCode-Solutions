class Solution
{
    public string RepeatLimitedString(string s, int repeatLimit)
    {
        var count = new Dictionary<char, int>();
        foreach (var c in s)
        {
            if (!count.ContainsKey(c)) count[c] = 0;
            count[c]++;
        }

        var pq = new PriorityQueue<(char c, int cnt), char>();
        foreach (var kvp in count)
            pq.Enqueue((kvp.Key, kvp.Value), (char)('z' - kvp.Key));

        var sb = new StringBuilder();

        while (pq.Count > 0)
        {
            var (currChar, currCount) = pq.Dequeue();

            int use = Math.Min(currCount, repeatLimit);
            sb.Append(new string(currChar, use));
            currCount -= use;

            if (currCount > 0)
            {
                if (pq.Count == 0) break;

                var (nextChar, nextCount) = pq.Dequeue();
                sb.Append(nextChar);
                nextCount--;

                if (nextCount > 0)
                    pq.Enqueue((nextChar, nextCount), (char)('z' - nextChar));

                pq.Enqueue((currChar, currCount), (char)('z' - currChar));
            }
        }

        return sb.ToString();
    }
}
