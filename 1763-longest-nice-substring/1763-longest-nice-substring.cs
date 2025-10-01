public class Solution
{
    public string LongestNiceSubstring(string s)
    {
        if (s.Length < 2)
            return "";

        var set = new HashSet<char>(s);

        for (int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            if (!(set.Contains(char.ToLower(c)) && set.Contains(char.ToUpper(c))))
            {
                string left = LongestNiceSubstring(s.Substring(0, i));
                string right = LongestNiceSubstring(s.Substring(i + 1));

                return left.Length >= right.Length ? left : right;
            }
        }

        return s;
    }
}
