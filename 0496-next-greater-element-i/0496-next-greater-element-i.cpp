class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stc;
        unordered_map<int, int> nextGreater;

        for (auto num : nums2) {
            while (!stc.empty() && num > stc.top())
            {
                nextGreater[stc.top()] = num;
                stc.pop();
            }
            stc.push(num);
        }

        while (!stc.empty()) {
            nextGreater[stc.top()] = -1;
            stc.pop();
        }

        vector<int> res;

        for (int num : nums1) {
            res.push_back(nextGreater[num]);
        }

        return res;
    }
};