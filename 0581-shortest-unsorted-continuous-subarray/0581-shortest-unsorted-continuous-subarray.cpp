class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;

        int maxSeen = nums[0];
        int minSeen = nums[n - 1];

        for (int i = 1; i < n; i++) {
            if (nums[i] < maxSeen) {
                right = i;
            } else {
                maxSeen = nums[i];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minSeen) {
                left = i;
            } else {
                minSeen = nums[i];
            }
        }

        return (right == -1) ? 0 : right - left + 1;
    }
};
