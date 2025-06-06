class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> max;

        for (int num : nums) {
            max.push(num);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            nums[i] = max.top();
            max.pop();
        }

        return nums;
    }
};
