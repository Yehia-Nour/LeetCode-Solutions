class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int l = 0;
        int r = str.length() - 1;
        while(l < r){
            if(str[l] != str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};