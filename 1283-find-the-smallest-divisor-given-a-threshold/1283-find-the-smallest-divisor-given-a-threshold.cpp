class Solution {
public:
    bool is_sum(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
            if (sum > threshold) 
                return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int start = 1, end = *max_element(nums.begin(), nums.end());
        int ans; 
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (is_sum(nums, mid, threshold)) {
                ans = mid; 
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};