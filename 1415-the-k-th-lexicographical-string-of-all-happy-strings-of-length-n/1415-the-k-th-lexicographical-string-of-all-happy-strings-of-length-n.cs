public class Solution
{
    string _abc = "abc";
    List<string> _strings = new List<string>();
    int _n;
    void BackTracking(int idx, string str)
    {
        if (str.Length == _n)
        {
            _strings.Add(str);
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            if (str.Length != 0 && str[str.Length - 1] == _abc[i])
                continue;

            BackTracking(i, str + _abc[i]);
        }
    }
    public string GetHappyString(int n, int k)
    {
        _n = n;
        BackTracking(0, "");

        if (k > _strings.Count)
            return "";

        return _strings[k - 1];
    }
}