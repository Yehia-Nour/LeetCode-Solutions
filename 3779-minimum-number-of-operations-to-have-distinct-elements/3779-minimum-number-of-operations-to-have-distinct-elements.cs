public class Solution {
    public int MinOperations(int[] nums) {
        int n = nums.Length;
        HashSet<int> seen = new HashSet<int>();
        int lastDuplicateIdx = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (seen.Contains(nums[i])) {
                lastDuplicateIdx = i;
                break;
            }
            seen.Add(nums[i]);
        }

        if (lastDuplicateIdx == -1) {
            return 0;
        }

        return (lastDuplicateIdx / 3) + 1;
    }
}