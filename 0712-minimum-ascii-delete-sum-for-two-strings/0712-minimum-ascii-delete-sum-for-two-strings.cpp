class Solution {
public:
    string s1, s2;
    const static int MAX_N = 1001;
    int memory[MAX_N][MAX_N];

    int dp(int i, int j) {
        if (i == s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++) sum += s2[k];
            return sum;
        }
        if (j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++) sum += s1[k];
            return sum;
        }

        auto &ret = memory[i][j];
        if (ret != -1) return ret;

        if (s1[i] == s2[j])
            return ret = dp(i + 1, j + 1);

        int choice1 = s1[i] + dp(i + 1, j);
        int choice2 = s2[j] + dp(i, j + 1);

        return ret = min(choice1, choice2);
    }

    int minimumDeleteSum(string str1, string str2) {
        s1 = str1;
        s2 = str2;
        memset(memory, -1, sizeof(memory));
        return dp(0, 0);
    }
};
