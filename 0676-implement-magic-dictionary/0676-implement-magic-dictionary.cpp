

class MagicDictionary {
private:
	static const int MAX_CHAR = 26;
	MagicDictionary* child[MAX_CHAR];
	bool isLeaf { };

public:
    MagicDictionary() {
        memset(child, 0, sizeof(child));
    }

    void insert(string str, int index = 0) {
        if (index == str.length()) isLeaf = 1;
        else {
            int cur = str[index] - 'a';
            if (!child[cur]) child[cur] = new MagicDictionary();
            child[cur]->insert(str, index + 1);
        }
    }

    bool word_exist(string str, int idx = 0) {
		if (idx == (int) str.size())
			return isLeaf;

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;

		return child[cur]->word_exist(str, idx + 1);
	}
    
    void buildDict(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); ++i) {
            insert(dictionary[i]);
        }
    }

    bool search(string searchWord) {
        for (int i = 0; i < searchWord.length(); ++i)    {
            char cpy = searchWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == cpy) continue;
                searchWord[i] = ch;
                if (word_exist(searchWord)) return true;
            }
            searchWord[i] = cpy;
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