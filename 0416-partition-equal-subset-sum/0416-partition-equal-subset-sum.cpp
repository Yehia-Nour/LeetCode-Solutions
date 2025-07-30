vector<int> numList;
const int MAX_N = 201;
const int MAX_T = 10001;
int memory[MAX_N][MAX_T];

bool canReach(int i, int t) {
    if (t == 0)
        return true;
    if (i >= (int)numList.size() || t < 0)
        return false;

    int &ret = memory[i][t];
    if (ret != -1)
        return ret;

    bool take = canReach(i + 1, t - numList[i]);
    bool skip = canReach(i + 1, t);

    return ret = take || skip;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        numList = nums;
        int total = 0;
        for (int num : nums)
            total += num;

        if (total % 2 != 0) return false;

        int target = total / 2;
        memset(memory, -1, sizeof(memory));
        return canReach(0, target);
    }
};