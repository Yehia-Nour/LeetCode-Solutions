class Solution {
public:
    bool is_triangle(int a, int b, int c) {
        return a + b > c && a + c > b && b + c > a;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a, b, c;
        for (int i = nums.size() - 3; i >= 0; --i) {
            a = nums[i];
            b = nums[i + 1];
            c = nums[i + 2];
            if (is_triangle(a, b, c)) return a + b + c;
        }

        return 0;
    }
};