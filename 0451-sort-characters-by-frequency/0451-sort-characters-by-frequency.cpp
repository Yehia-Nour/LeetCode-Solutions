class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto& it : freq) {
            maxHeap.push({it.second, it.first});
        }

        string res = "";
        while (!maxHeap.empty()) {
            res.append(maxHeap.top().first, maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};