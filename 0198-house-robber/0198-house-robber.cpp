vector<int> numList;
const int MAX_N = 100;
int memory[MAX_N];

class Solution {
public:
    int dp(int i) {
        if (i >= numList.size()) return 0;

        int &ret = memory[i];
        if (ret != -1) return ret;

        int rob = numList[i] + dp(i + 2);
        int skip = dp(i + 1);

        return ret = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        numList = nums;
        memset(memory, -1, sizeof(memory));
        return dp(0);
    }
};