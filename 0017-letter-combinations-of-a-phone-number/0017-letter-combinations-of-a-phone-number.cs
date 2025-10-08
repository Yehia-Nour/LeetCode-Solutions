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

    void Backtrack(string digits, int start, string str)
    {
        if (str.Length == digits.Length)
        {
            _res.Add(str);
            return;
        }

        for( int i = start; i < digits.Length; i++ )
        {
            for( int j = 0; j < _phoneMap[digits[i]].Length; j++ )
            {
                str += _phoneMap[digits[i]][j];
                Backtrack(digits, i + 1, str);
                str = str.Substring(0, str.Length - 1);

            }
        }
    }

    public IList<string> LetterCombinations(string digits)
    {
        if (digits.Length == 0)
            return _res;

        string str = "";
        Backtrack(digits, 0, str);
        return _res;
    }
}