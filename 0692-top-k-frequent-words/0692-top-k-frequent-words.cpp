class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (const string& word : words) {
            freqMap[word]++;
        }

        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            minHeap(cmp);

        for (const auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<string> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = minHeap.top().second;
            minHeap.pop();
        }

        return result;
    }
};