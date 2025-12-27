public class Solution {
    public string ReorganizeString(string s) {
        var freq = new Dictionary<char, int>();
        foreach (char c in s)
        {
            if (!freq.ContainsKey(c))
                freq[c] = 0;
            freq[c]++;
        }

        var maxHeap = new PriorityQueue<char, int>();
        foreach (var kvp in freq)
            maxHeap.Enqueue(kvp.Key, -kvp.Value);

        var result = new StringBuilder();
        char prevChar = '\0';
        int prevCount = 0;

        while (maxHeap.Count > 0)
        {
            maxHeap.TryDequeue(out char currentChar, out int currentCount);
            currentCount = -currentCount;

            result.Append(currentChar);
            currentCount--;

            if (prevCount > 0)
                maxHeap.Enqueue(prevChar, -prevCount);

            prevChar = currentChar;
            prevCount = currentCount;
        }
        
        return result.Length == s.Length ? result.ToString() : "";
    }
}