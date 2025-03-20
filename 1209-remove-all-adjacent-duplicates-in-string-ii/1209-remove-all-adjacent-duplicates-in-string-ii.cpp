class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stc;

        for (char c : s) {
            if (!stc.empty() && stc.top().first == c) {
                stc.top().second++;
            } else {
                stc.push({c, 1});
            }

            if (stc.top().second == k) {
                stc.pop();
            }
        }

        string res = "";

        while (!stc.empty()) {
            res = string(stc.top().second, stc.top().first) + res;
            stc.pop();
        }

        return res;
    }
};