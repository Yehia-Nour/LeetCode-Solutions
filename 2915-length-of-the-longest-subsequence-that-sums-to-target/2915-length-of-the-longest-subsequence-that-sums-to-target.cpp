vector<int> numsC;
const int MAX_N = 1000;
const int MAX_TARGET = 1001;
int memory[MAX_N][MAX_TARGET];

int dp (int i, int target) {
    if (target == 0) return 0;
    if (i == numsC.size() || target < 0) return -1;

    int &ret = memory[i][target];
    if (ret != -2) return ret;

    int take = -1;
    int t = dp(i + 1, target - numsC[i]);
    if (t != -1) take = 1 + t;

    int skip = dp(i + 1, target);

    return ret = max(take, skip);
}

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        numsC = nums;
        for (int i = 0; i < MAX_N; ++i)
            for (int j = 0; j < MAX_TARGET; ++j)
                memory[i][j] = -2;

        return dp(0, target);
    }
};
