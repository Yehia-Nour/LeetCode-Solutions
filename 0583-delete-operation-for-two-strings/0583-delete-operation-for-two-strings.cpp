string w1, w2;
const int MAX_N = 501;
int memory[MAX_N][MAX_N];
class Solution {
public:
    int lcs(int i, int j) {
        if (i == w1.size() || j == w2.size()) return 0;

        auto &ret = memory[i][j];
        if (ret != -1) return ret;

        if (w1[i] == w2[j]) {
            return ret = 1 + lcs(i + 1, j + 1);
        }

        int choice1 = lcs(i + 1, j);
        int choice2 = lcs(i, j + 1);

        return ret = max(choice1, choice2);
    }

    int minDistance(string word1, string word2) {
        w1 = word1;
        w2 = word2;

        memset(memory, -1, sizeof(memory));
        int LCS = lcs(0, 0);

        return (w1.size() - LCS) + (w2.size() - LCS);
    }
};