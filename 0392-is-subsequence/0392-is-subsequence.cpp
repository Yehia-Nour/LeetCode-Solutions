class Solution {
public:
    string s, t;
    int memo[105][10005]; 
    bool solve(int i, int j) {
        if (i == s.size()) return true;
        if (j == t.size()) return false;

        int &ret = memo[i][j];
        if (ret != -1) return ret;

        if (s[i] == t[j]) 
            return ret = solve(i + 1, j + 1);
        else 
            return ret = solve(i, j + 1);
    }

    bool isSubsequence(string s1, string t1) {
        s = s1;
        t = t1;
        memset(memo, -1, sizeof(memo));
        return solve(0, 0);
    }
};
