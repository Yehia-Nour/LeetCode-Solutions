public class MedianFinder
{
    PriorityQueue<int, int> small;
    PriorityQueue<int, int> large;

    public MedianFinder()
    {
        small = new();
        large = new();
    }

    public void AddNum(int num)
    {
        small.Enqueue(num, -num);

        if (large.Count > 0 && small.Peek() > large.Peek())
        {
            int value = small.Dequeue();
            large.Enqueue(value, value);
        }

        if (small.Count > large.Count + 1)
        {
            int value = small.Dequeue();
            large.Enqueue(value, value);
        }
        else if (large.Count > small.Count)
        {
            int value = large.Dequeue();
            small.Enqueue(value, -value);
        }
    }

    public double FindMedian()
    {
        if (small.Count > large.Count)
            return small.Peek();

        return (small.Peek() + large.Peek()) / 2.0;
    }
}
