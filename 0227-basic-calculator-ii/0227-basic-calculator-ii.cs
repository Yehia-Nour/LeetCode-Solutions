public class Solution
{
    public int Calculate(string s)
    {
        if (string.IsNullOrEmpty(s)) return 0;

        Stack<long> st = [];
        long num = 0;
        char sign = '+';

        for (int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            if (char.IsDigit(c))
                num = num * 10 + (c - '0');

            if ((!char.IsDigit(c) && c != ' ') || i == s.Length - 1)
            {
                if (sign == '+')
                    st.Push(num);
                else if (sign == '-')
                    st.Push(-num);
                else if (sign == '*')
                {
                    long prev = st.Pop();
                    st.Push(prev * num);
                }
                else if (sign == '/')
                {
                    long prev = st.Pop();
                    st.Push(prev / num);
                }

                sign = c;
                num = 0;
            }
        }

        long result = 0;
        while (st.Count > 0) result += st.Pop();

        return (int)result;
    }
}
