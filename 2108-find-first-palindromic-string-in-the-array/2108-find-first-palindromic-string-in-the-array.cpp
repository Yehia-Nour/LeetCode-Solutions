class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string res = "";
        bool check;
        int j, k;
        for(int i = 0; i < words.size(); i++)
        {
            check = true;
            j = 0;
            k = words[i].size() - 1;
            while(j < words[i].size() / 2)
            {
            if (words[i][j] != words[i][k]) {
                check = false;
                break;
            }
                j++;
                k--;
            }
            if(check)
            {
                res =  words[i];
                return res;
            }
        }
        return res;
    }
};