class Solution {
public:
    bool is_sum(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil(static_cast<double>(num) / divisor);
            if (sum > threshold) 
                return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_num = 0;
        for (int num : nums) {
            if (num > max_num) max_num = num;
        }

        int start = 1, end = max_num, ans = 0; 
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