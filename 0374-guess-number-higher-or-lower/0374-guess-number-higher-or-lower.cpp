class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        int m;

        while (l <= h) {
            m = l + (h - l) / 2;

            int result = guess(m);

            if (result == 0) return m;
            else if (result == 1) l = m + 1;
            else h = m - 1;
        }

        return -1;
    }
};
