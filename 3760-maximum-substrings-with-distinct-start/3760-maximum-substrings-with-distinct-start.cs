public class Solution {
    public int MaxDistinct(string s) {
        HashSet<char> set = [];
        foreach (char c in s)
            set.Add(c);

        return set.Count;
    }
}