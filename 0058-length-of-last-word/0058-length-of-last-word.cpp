class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int result = 0;
        while(true)
        {
            if(isalpha(s[i])) break;
            i--;
        }
        while(i < s.length())
        {
            if(s[i] == ' ') break;
            i--;
            result++;
        }
        return result;
    }
};