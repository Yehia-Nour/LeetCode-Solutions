class MagicDictionary {
private:
    unordered_set<string> wordSet;
    unordered_map<int, vector<string>> lengthMap;

public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (const string& word : dictionary) {
            wordSet.insert(word);
            lengthMap[word.length()].push_back(word);
        }
    }

    bool search(string searchWord) {
        int len = searchWord.length();

         if (lengthMap.find(len) == lengthMap.end()) return false;

        for (const string& dictWord : lengthMap[len]) {
            int diffCount = 0;
            for (int i = 0; i < len; ++i) {
                if (searchWord[i] != dictWord[i]) {
                    if (++diffCount > 1) break; 
                }
            }
            if (diffCount == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */