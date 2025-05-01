class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map <int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        int res = 0;

        for (auto pair : map) {
            int count = pair.second;
            res += count * (count - 1) / 2;
        }

        return res;
    }
};
