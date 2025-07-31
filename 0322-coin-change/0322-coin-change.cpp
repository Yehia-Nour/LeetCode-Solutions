#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
const int MAX_N = 12;
const int MAX_AMOUNT = 10000 + 1;
const int INF = 1e9;

int memory[MAX_N][MAX_AMOUNT];

int dp(int i, int remain) {
    if (remain == 0) return 0;
    if (i == (int)coins.size() || remain < 0) return INF;

    int &ret = memory[i][remain];
    if (ret != -1) return ret;

    int take = 1 + dp(i, remain - coins[i]);
    int skip = dp(i + 1, remain);

    return ret = min(take, skip);
}

class Solution {
public:
    int coinChange(vector<int>& inputCoins, int amount) {
        coins = inputCoins;
        memset(memory, -1, sizeof(memory));

        int ans = dp(0, amount);
        return (ans >= INF) ? -1 : ans;
    }
};
