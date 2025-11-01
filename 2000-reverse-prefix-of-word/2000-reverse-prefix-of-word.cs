public class Solution
{
    public string ReversePrefix(string word, char ch)
    {
        int index = word.IndexOf(ch);
        if (index == -1)
            return word;

        string prefix = word.Substring(0, index + 1);
        char[] arr = prefix.ToCharArray();
        Array.Reverse(arr);

        return new string(arr) + word.Substring(index + 1);
    }
}
