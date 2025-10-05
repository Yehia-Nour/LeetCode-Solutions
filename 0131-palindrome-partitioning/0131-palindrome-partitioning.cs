public class Solution
{
    IList<IList<string>> result = new List<IList<string>>();

    void Backtrack(string s, int start, List<string> currentList)
    {
        if (start == s.Length)
        {
            result.Add(new List<string>(currentList));
            return;
        }

        for (int end = start; end < s.Length; end++)
        {
            string substring = s.Substring(start, end - start + 1);

            if (IsPalindrome(substring))
            {
                currentList.Add(substring);
                Backtrack(s, end + 1, currentList);
                currentList.RemoveAt(currentList.Count - 1);
            }
        }
    }

    bool IsPalindrome(string str)
    {
        int left = 0, right = str.Length - 1;
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    public IList<IList<string>> Partition(string s)
    {
        Backtrack(s, 0, new List<string>());
        return result;
    }
}
