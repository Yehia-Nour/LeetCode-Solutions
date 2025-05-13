class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> orderMap;

    for (int i = 0; i < order.size(); ++i) {
        orderMap[order[i]] = i;
    }

    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i];
        string word2 = words[i + 1];

        bool valid = false;

        for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
            char c1 = word1[j];
            char c2 = word2[j];

            if (orderMap[c1] < orderMap[c2]) {
                valid = true;
                break;
            } else if (orderMap[c1] > orderMap[c2]) {
                return false;
            }
        }

        if (!valid && word1.size() > word2.size()) {
            return false;
        }
    }

    return true;  
    }
};