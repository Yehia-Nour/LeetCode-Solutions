vector<int> numList;
const int MAX = 2500 + 1;
int memory[MAX][MAX];

int LIS(int i, int prev) {
	if (i == (int) numList.size())
		return 0;

	auto &ret = memory[i][prev];

	if (ret != -1)
		return ret;

	int choice1 = LIS(i + 1, prev);
	int choice2 = 0;

	if (prev >= (int)numList.size() || numList[prev] < numList[i])
		choice2 = 1 + LIS(i + 1, i);

	return ret = max(choice1, choice2);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	numList = nums;
    	memset(memory, -1, sizeof(memory));
    	return LIS(0, numList.size());
    }
};