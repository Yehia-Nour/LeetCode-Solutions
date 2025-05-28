class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto num : arr) {
            map[num]++;
        }

        for (auto pair : map) {
            minHeap.push({pair.second, pair.first});
        }

        for (int i = 0; i < k; i++) {
            auto top = minHeap.top(); 
            minHeap.pop();

            top.first -= 1;

            minHeap.push(top);

            if (minHeap.top().first == 0) {
                minHeap.pop();
            }
        }

        return minHeap.size();
    }
};