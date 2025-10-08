public class Solution
{
    void Backtrack(string s, int start, List<string> parts, List<string> result)
    {
        if (parts.Count == 4 && start == s.Length)
        {
            result.Add(string.Join(".", parts));
            return;
        }

        if (parts.Count >= 4) return;

        for (int len = 1; len <= 3 && start + len <= s.Length; len++)
        {
            string part = s.Substring(start, len);

            if ((part.StartsWith("0") && part.Length > 1) || int.Parse(part) > 255)
                continue;

            parts.Add(part);
            Backtrack(s, start + len, parts, result);
            parts.RemoveAt(parts.Count - 1);
        }
    }

    public IList<string> RestoreIpAddresses(string s)
    {
        var result = new List<string>();
        Backtrack(s, 0, new List<string>(), result);
        return result;
    }
}
