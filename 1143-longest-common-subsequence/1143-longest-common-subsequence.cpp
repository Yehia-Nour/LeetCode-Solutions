string str1, str2;

const int MAX = 1000 + 1;
int memory[MAX][MAX];

int LCS(int i, int j) {
	if (i == (int) str1.size() || j == (int) str2.size())
		return 0;

	auto &ret = memory[i][j];
	if (ret != -1)
		return ret;

	if (str1[i] == str2[j])
		return ret = 1 + LCS(i + 1, j + 1);

	int choice1 = LCS(i + 1, j);
	int choice2 = LCS(i, j + 1);
	return ret = max(choice1, choice2);
}

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		str1 = text1, str2 = text2;

		memset(memory, -1, sizeof(memory));
		return LCS(0, 0);
	}
};