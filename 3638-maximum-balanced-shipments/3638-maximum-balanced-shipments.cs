public class Solution {
    public int MaxBalancedShipments(int[] weight) {
        int n = weight.Length;
        int count = 0;
        int currentMax = weight[0];

        for (int i = 0; i < n; i++) {
            currentMax = int.Max(currentMax, weight[i]);

            if (weight[i] < currentMax) {
                count++;
                if (i + 1 < n)
                    currentMax = weight[i + 1];
            }
        }

        return count;
    }
}
