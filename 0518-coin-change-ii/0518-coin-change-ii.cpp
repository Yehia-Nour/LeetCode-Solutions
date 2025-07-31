vector<int> inputCoins;
const int MAX_N = 300;
const int MAX_AMOUNT = 5000 + 1;

int memory[MAX_N][MAX_AMOUNT];
int dp(int i, int remain) {
    if (remain == 0) return 1;
    if (i == inputCoins.size() || remain < 0) return 0;

    int &ret = memory[i][remain];
    if (ret != -1) return ret;

    int take = dp(i, remain - inputCoins[i]);
    int skip = dp(i + 1, remain);

    return ret = take + skip;
}
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        inputCoins = coins;
        memset(memory, -1, sizeof(memory));
        return dp(0, amount);
    }
};