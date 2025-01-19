class Solution {
public:
    double minimumAverage(std::vector<int>& nums) {
        std::vector<double> vec;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n / 2; i++) {
            vec.push_back(static_cast<double>(nums[i] + nums[n - i - 1]) / 2.0);
        }
        
        auto minElement = std::min_element(vec.begin(), vec.end());
        
        return *minElement;
    }
};