class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;

        for (auto num : nums) {
            set.insert(num);
        }

        for (int i = 0; i <= nums.size(); ++i) {
            if (!set.count(i)) return i;
        }

        return 0;
    }
};