vector<vector<int>> p;
const int OFFSET = 1001;

int memory[1001][2002]; 

int dp(int i, int last) {
    if (i == p.size()) return 0;

    int &ret = memory[i][last + OFFSET];
    if (ret != -1) return ret;

    int skip = dp(i + 1, last);

    int take = 0;
    
    if (last == -OFFSET || p[last][1] < p[i][0]) {
        take = 1 + dp(i + 1, i);
    }

    return ret = max(take, skip);
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        p = pairs;

        memset(memory, -1, sizeof(memory));
        return dp(0, -OFFSET);
    }
};
