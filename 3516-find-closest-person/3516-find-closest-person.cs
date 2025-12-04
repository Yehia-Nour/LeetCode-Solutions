public class Solution {
    public int FindClosest(int x, int y, int z) {
        int d1 = Math.Abs(x - z);
        int d2 = Math.Abs(y - z);

        if (d1 < d2) return 1;
        else if (d2 < d1) return 2;
        else return 0;
    }
}