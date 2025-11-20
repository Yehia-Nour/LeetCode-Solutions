public class Solution {
    public int MinChanges(int[] nums, int k) {
        int n = nums.Length;
        int m = n / 2;
        int maxX = k;

        int[] diff = new int[maxX + 2];
        int[] cntD = new int[maxX + 1];

        for (int i = 0; i < m; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int low = Math.Min(a, b);
            int high = Math.Max(a, b);
            int d = high - low;
            cntD[d]++;

            int R = Math.Max(high, k - low);
            diff[0]++;
            diff[R + 1]--;
        }

        int bestCover = 0;
        int cur = 0;

        for (int X = 0; X <= maxX; X++) {
            cur += diff[X];
            int cover = cur + cntD[X];
            if (cover > bestCover)
                bestCover = cover;
        }

        return 2 * m - bestCover;
    }
}