public class Solution
{
    Dictionary<char, string> _phoneMap = new Dictionary<char, string>
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    List<string> _res = new List<string>();

    void Backtrack(string digits, int index, string str)
    {
        if (str.Length == digits.Length)
        {
            _res.Add(str);
            return;
        }

        string letters = _phoneMap[digits[index]];

        foreach (char letter in letters)
        {
            Backtrack(digits, index + 1, str + letter);
        }
    }

    public IList<string> LetterCombinations(string digits)
    {
        if (digits.Length == 0)
            return _res;

        Backtrack(digits, 0, "");
        return _res;
    }
}
