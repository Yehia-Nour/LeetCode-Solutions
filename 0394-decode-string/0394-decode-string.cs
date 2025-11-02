public class Solution
{
    int i = 0;
    
    string Helper(string s)
    {
        string result = "";
        int num = 0;

        while (i < s.Length)
        {
            char ch = s[i];

            if (char.IsDigit(ch))
            {
                num = num * 10 + (ch - '0');
                i++;
            }
            else if (ch == '[')
            {
                i++; 
                string sub = Helper(s);
                while (num-- > 0)
                    result += sub;
                num = 0;
            }
            else if (ch == ']')
            {
                i++;
                return result;
            }
            else
            {
                result += ch;
                i++;
            }
        }

        return result;
    }

    public string DecodeString(string s)
    {
        return Helper(s);
    }
}
