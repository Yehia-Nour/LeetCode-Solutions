public class Solution
{
    IList<string> _res = new List<string>();
    int _len;

    void Backtrack(string strPath)
    { 
        if (strPath.Length == _len)
        {
            _res.Add(strPath);
            return;
        }

        strPath += '1';
        Backtrack(strPath);
        strPath = strPath.Substring(0, strPath.Length - 1);
        
        if (strPath.Length != 0 && strPath[strPath.Length - 1] == '0')
            return;

        strPath += '0';
        Backtrack(strPath);
        strPath = strPath.Substring(0, strPath.Length - 1);
    }

    public IList<string> ValidStrings(int n)
    {
        _len = n;
        string str = "";

        Backtrack(str);

        return _res;
    }
}
