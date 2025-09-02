public class Solution
{
    const int MAX_T = 5000 + 1;
    int[] memory = new int[MAX_T];
    List<int> numbers;

    private int CombinationSum(int target)
    {
        if (target < 0)
            return 0;

        if (target == 0)
            return 1; 

        if (memory[target] != -1)
            return memory[target];

        int ret = 0;
        foreach (var value in numbers)
            ret += CombinationSum(target - value);

        memory[target] = ret;
        return ret;
    }

    public int CombinationSum4(int[] nums, int target)
    {
        numbers = new List<int>(nums);
        Array.Fill(memory, -1);
        return CombinationSum(target);
    }
}