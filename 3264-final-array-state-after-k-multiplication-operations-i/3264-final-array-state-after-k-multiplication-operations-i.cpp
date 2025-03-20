class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> minHeap;

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i], i});
        }

        int temp;
        int indexTemp;

        for (int i = 0; i < k; ++i) {
            temp = minHeap.top().first;
            indexTemp = minHeap.top().second;

            minHeap.pop();
            minHeap.push({temp * multiplier, indexTemp});
        }

        while (!minHeap.empty()) {
            nums[minHeap.top().second] = minHeap.top().first;
            minHeap.pop();
        }

        return nums;
    }
};