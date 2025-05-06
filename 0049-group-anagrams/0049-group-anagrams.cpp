class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < strs.size(); ++i) {
            string word = strs[i];
            sort(word.begin(), word.end());
            map[word].push_back(strs[i]);
        }

        vector<vector<string>> vec;

        for (auto pair : map) {
            vec.push_back(pair.second);
        }

        return vec;
    }
};