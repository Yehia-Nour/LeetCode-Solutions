class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map <char, int> map;

        for (int i = 0; i < jewels.length(); i++) {
            map[jewels[i]] = 0;
        }

        int res = 0;

        for (char stone : stones) {
            if (map.find(stone) != map.end()) {
                res++;
            }
        }

        return res;
    }
};