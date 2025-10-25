public class Solution
{
    public string RemoveKdigits(string num, int k)
    {
        if (k >= num.Length)
            return "0";

        Stack<char> stack = [];

        foreach (char c in num)
        {
            while (stack.Count > 0 && k > 0 && stack.Peek() > c)
            {
                stack.Pop();
                k--;
            }

            stack.Push(c);
        }

        while (k > 0 && stack.Count > 0)
        {
            stack.Pop();
            k--;
        }

        char[] arr = stack.Reverse().ToArray();
        string result = new(arr);

        result = result.TrimStart('0');

        if (result == "")
            return "0";

        return result;
    }
}
