string str1, str2;
const int MAX_N = 500 + 1;
int memory[MAX_N][MAX_N];

class Solution {
public:
    int edit(int i, int j) {
        if (i == str1.length())
            return str2.length() - j;
        if (j == str2.length())
            return str1.length() - i;

        auto& ret = memory[i][j];
        if (ret != -1)
            return memory[i][j];

        if (str1[i] == str2[j])
            return edit(i + 1, j + 1);

        int delete_ = 1 + edit(i + 1, j);
        int insert = 1 + edit(i, j + 1);
        int change = 1 + edit(i + 1, j + 1);
        return ret = min(min(insert, delete_), change);
    }

    int minDistance(string word1, string word2) {
        str1 = word1;
        str2 = word2;

        memset(memory, -1, sizeof(memory));
        return edit(0, 0);
    }
};