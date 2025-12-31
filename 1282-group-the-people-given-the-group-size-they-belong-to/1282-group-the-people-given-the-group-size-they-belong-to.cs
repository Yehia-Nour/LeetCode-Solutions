public class Solution
{
    public IList<IList<int>> GroupThePeople(int[] groupSizes)
    {
        var groups = new Dictionary<int, List<int>>();
        var result = new List<IList<int>>();

        for (int i = 0; i < groupSizes.Length; i++)
        {
            int size = groupSizes[i];

            if (!groups.ContainsKey(size))
                groups[size] = new List<int>();

            groups[size].Add(i);

            if (groups[size].Count == size)
            {
                result.Add(new List<int>(groups[size]));
                groups[size].Clear();
            }
        }

        return result;
    }
}
