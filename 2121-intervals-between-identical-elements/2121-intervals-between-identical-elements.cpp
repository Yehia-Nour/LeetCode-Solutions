class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]].push_back(i);
        }

        vector<long long> res(nums.size());

        for (auto& [num, indices] : map) {
            int n = indices.size();
            if (n == 1) continue;

            vector<long long> prefix(n + 1, 0);
            for (int i = 0; i < n; ++i) {
                prefix[i + 1] = prefix[i] + indices[i];
            }

            for (int i = 0; i < n; ++i) {
                long long left = (long long)indices[i] * i - prefix[i];
                long long right = (prefix[n] - prefix[i + 1]) - (long long)indices[i] * (n - i - 1);
                res[indices[i]] = left + right;
            }
        }

        return res;
    }
};
