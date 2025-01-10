class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0;
        int r = 1;
        for(int i = 0; i < nums.size() / 2; i++)
        {
            if(nums[l] != nums[r]) return nums[l];
            l += 2;
            r += 2;
        }
        return nums[nums.size() - 1];
    }
};