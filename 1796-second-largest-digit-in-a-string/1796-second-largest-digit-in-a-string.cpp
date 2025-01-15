class Solution {
public:
    int secondHighest(string s) {
        map<int, int> mp;
        for(char ch : s)
        {
            if(isdigit(ch))
            {
                mp[ch - '0']++;
            }
        }
        if(mp.empty() || mp.size() == 1)
        {
            return -1;
        }
        else
        {
            auto secondLastElement = ++mp.rbegin();
            int secondLastValue = secondLastElement->first;
            return secondLastValue;
        }
    }
};