class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); ++i) {
            map[arr[i]]++;
        }

        unordered_set<int> set;

        for (auto pair : map) {
            if (!set.empty() && set.count(pair.second))
                return false;
            set.insert(pair.second);
        }

        return true;
    }
};