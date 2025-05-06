class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }

        for (auto pair : map) {
            maxHeap.push({pair.second, pair.first});
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};