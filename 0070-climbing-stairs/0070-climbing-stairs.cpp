const int MAX_N = 46;
int memory[MAX_N];
class Solution {
public:
    int dp(int n){
        if (n == 0 || n == 1) return 1;

        auto &ret = memory[n];
        if (ret != -1) return ret;

        return ret = dp(n - 1) + dp(n - 2);
    }

    int climbStairs(int n) {
        memset(memory, -1, sizeof(memory));

        return dp(n);
    }
};