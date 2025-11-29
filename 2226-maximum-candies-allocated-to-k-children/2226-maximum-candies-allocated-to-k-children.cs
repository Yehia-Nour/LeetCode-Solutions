public class Solution {
    public int MaximumCandies(int[] candies, long k) {
        int left = 1, right = candies.Max();
        int result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            long childrenCount = 0;

            foreach (int candy in candies) {
                childrenCount += candy / mid;
            }

            if (childrenCount >= k) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}