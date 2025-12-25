public class Solution
{
    public int MinimumLengthEncoding(string[] words)
    {
        HashSet<string> set = new HashSet<string>(words);

        foreach (var word in words)
        {
            for (int i = 1; i < word.Length; i++)
            {
                string suffix = word.Substring(i);
                set.Remove(suffix);
            }
        }

        int result = 0;

        foreach (var word in set)
            result += word.Length + 1;

        return result;
    }
}
