class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.length() != t.length()) return false;

        std::map<char, int> mp1;
        std::map<char, int> mp2;

        for(int i = 0; i < s.length(); i++) {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }

        if (mp1 == mp2) {
            return true;
        } else {
            return false;
        }
    }
};