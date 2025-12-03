class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxLength = 0;

        HashSet<char> seen = [];


        for (int i = 0; i < s.Length; i++)
        {
            while (seen.Contains(s[i]))
                seen.Remove(s[left++]);

            seen.Add(s[i]);
            maxLength = int.Max(maxLength, i - left + 1);
        }

        return maxLength;
    }
}