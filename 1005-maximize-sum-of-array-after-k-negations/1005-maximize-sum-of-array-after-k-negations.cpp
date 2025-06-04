class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0; ++i) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                --k;
            } else {
                break;
            }
        }

        if (k % 2 != 0) {
            int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minIndex] *= -1;
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};