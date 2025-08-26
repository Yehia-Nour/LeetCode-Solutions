    string str;
    const int MAX_N = 10001;
    int memory[MAX_N][MAX_N];
class Solution {
    int dp(int start, int end) {
        if (start >= end) return 1;
        
        auto &ret = memory[start][end];
        if (ret != -1) return ret;

        if (str[start] != str[end]) return 0;

        return ret = dp(start + 1, end - 1);
    }
public:
    int countSubstrings(string s) {
        str = s;
        
        memset(memory, -1, sizeof(memory));

        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (dp(i, j)) sum++;
            }
        }

        return sum + s.length();
    }
};