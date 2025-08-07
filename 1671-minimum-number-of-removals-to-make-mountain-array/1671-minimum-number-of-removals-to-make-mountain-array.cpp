class Solution {
public:
    static const int MAX = 1001;
    int memory_lds[MAX];
    int memory_lis[MAX];

    int LDS_START(int cur, const vector<int>& nums) {
        if (cur == nums.size())
            return 0;

        int& ret = memory_lds[cur];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int next = cur + 1; next < nums.size(); ++next) {
            if (nums[cur] > nums[next])	
                ret = max(ret, LDS_START(next, nums));
        }

        ret += 1;
        return ret;
    }

    int LIS_END(int cur, const vector<int>& nums) {
        if (cur == -1)
            return 0;

        int& ret = memory_lis[cur];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int prev = cur - 1; prev >= 0; --prev) {
            if (nums[prev] < nums[cur])
                ret = max(ret, LIS_END(prev, nums));
        }

        ret += 1;
        return ret;
    }

    int minimumMountainRemovals(const vector<int>& nums) {
        int sz = nums.size();
        memset(memory_lds, -1, sizeof(memory_lds));
        memset(memory_lis, -1, sizeof(memory_lis));

        int longest_inc_dec = 0;

        for (int i = 0; i < sz; ++i) {
            int left = LIS_END(i, nums);
            int right = LDS_START(i, nums);

            if (left < 2 || right < 2)
                continue;

            int cur = left + right - 1;
            longest_inc_dec = max(longest_inc_dec, cur);
        }

        return sz - longest_inc_dec;
    }
};
