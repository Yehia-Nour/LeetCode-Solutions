vector<int> numList;
const int MAX_N = 21;
const int OFFSET = 1000;
const int MAX_SUM = 2001;
int memory[MAX_N][MAX_SUM];

int countWays(int i, int sumSoFar, int target) {
    if (i == (int)numList.size())
        return sumSoFar == target ? 1 : 0;

    int &ret = memory[i][sumSoFar + OFFSET];
    if (ret != -1)
        return ret;

    int plus = countWays(i + 1, sumSoFar + numList[i], target);
    int minus = countWays(i + 1, sumSoFar - numList[i], target);

    return ret = plus + minus;
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        numList = nums;
        memset(memory, -1, sizeof(memory));
        return countWays(0, 0, target);
    }
};
