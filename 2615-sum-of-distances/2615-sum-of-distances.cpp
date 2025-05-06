class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]].push_back(i);
        }

        vector<long long> vec(nums.size());

        for (auto& [num, indices] : map) {
            int n = indices.size();
            vector<long long> prefix(n, 0);
            for (int i = 1; i < n; ++i) {
                prefix[i] = prefix[i - 1] + indices[i];
            }

            for (int i = 0; i < n; ++i) {
                long long left = (long long)i * indices[i] - (i == 0 ? 0 : prefix[i - 1]);
                long long right = (prefix[n - 1] - prefix[i]) - (long long)(n - 1 - i) * indices[i];
                vec[indices[i]] = left + right;
            }
        }

        return vec;
    }
};
