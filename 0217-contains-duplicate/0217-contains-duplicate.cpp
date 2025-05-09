class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        for (auto pair : map) {
            if (pair.second > 1) return true;
        }

        return false;
    }
};
