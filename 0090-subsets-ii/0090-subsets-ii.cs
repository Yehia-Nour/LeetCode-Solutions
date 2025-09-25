public class Solution {
    void Backtrack(int[] nums, int index, List<int> path, IList<IList<int>> result) {
    result.Add(new List<int>(path));

    for (int i = index; i < nums.Length; i++) {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        path.Add(nums[i]); 
        Backtrack(nums, i + 1, path, result); 
        path.RemoveAt(path.Count - 1);
    }
}
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        var result = new List<IList<int>>();
        Array.Sort(nums);

        Backtrack(nums, 0, new List<int>(), result);
        return result;
    }
}