class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }

        vector<int> res;

        for (auto pair : map) {
            if (pair.second == 2) res.push_back(pair.first);
        }

        return res;
    }
};