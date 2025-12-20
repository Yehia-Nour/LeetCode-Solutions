public class Solution
{
    public int LargestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit)
    {
        var items = new List<(int value, int label)>();
        for (int i = 0; i < values.Length; i++)
            items.Add((values[i], labels[i]));

        items.Sort((a, b) => b.value.CompareTo(a.value));

        Dictionary<int, int> labelCount = [];

        int sum = 0;
        int taken = 0;

        foreach (var item in items)
        {
            if (taken == numWanted)
                break;

            if (!labelCount.ContainsKey(item.label))
                labelCount[item.label] = 0;


            if (labelCount[item.label] < useLimit)
            {
                sum += item.value;
                labelCount[item.label]++;
                taken++;
            }
        }

        return sum;
    }
}