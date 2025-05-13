class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        while (!count.empty()) {
            int start = count.begin()->first;

            for (int i = 0; i < groupSize; ++i) {
                int curr = start + i;

                if (count.find(curr) == count.end())
                    return false;

                count[curr]--;
                if (count[curr] == 0) {
                    count.erase(curr);
                }
            }
        }

        return true;
    }
};