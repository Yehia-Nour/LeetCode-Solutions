class Solution {
public:
    vector<int> costs;
    int memory[1005];  

    int dp(int i) {
        if (i >= costs.size()) return 0;  
        
        int &ret = memory[i];
        if (ret != -1) return ret;

        int one_step = dp(i + 1);
        int two_step = dp(i + 2);

        return ret = costs[i] + min(one_step, two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        costs = cost;
        memset(memory, -1, sizeof(memory));

        return min(dp(0), dp(1));
    }
};