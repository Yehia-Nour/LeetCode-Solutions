class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
            std::string str1, str2;
    
    for (const auto& part : word1) {
        str1 += part;
    }
    
    for (const auto& part : word2) {
        str2 += part;
    }
    
    return str1 == str2;
    }
};