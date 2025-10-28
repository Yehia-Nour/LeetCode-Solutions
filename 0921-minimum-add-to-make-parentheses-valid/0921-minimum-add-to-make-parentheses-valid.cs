public class Solution {
    public int MinAddToMakeValid(string s) {
        Stack<char> stack = [];
        int needLeft = 0;

        foreach (char c in s)
        {
            if (c == '(')
                stack.Push(c);
            else 
            {
                if (stack.Count > 0)
                    stack.Pop();
                else
                    needLeft++;
            }
        }

        return needLeft + stack.Count;
    }
}
