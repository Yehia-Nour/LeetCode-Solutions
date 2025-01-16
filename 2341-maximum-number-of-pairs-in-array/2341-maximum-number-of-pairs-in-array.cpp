class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;
        unordered_map<int, int> mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        for (const auto& pair : mp)
        {
            if(pair.second % 2 == 0)
            {
                num1 += pair.second / 2;
            }
            else
            {
                num2++;
                num1 += (pair.second - 1) / 2;
            }
        }
        return {num1, num2};
    }
};