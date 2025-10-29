public class Solution
{
    double Gain(int pass, int total)
    {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    public double MaxAverageRatio(int[][] classes, int extraStudents)
    {
        var pq = new PriorityQueue<(int pass, int total), double>();

        foreach (var item in classes)
        {
            double gain = Gain(item[0], item[1]);
            pq.Enqueue((item[0], item[1]), -gain);
        }

        while (extraStudents-- > 0)
        {
            var (pass, total) = pq.Dequeue();
            pass++;
            total++;
            pq.Enqueue((pass, total), -Gain(pass, total));
        }

        double res = 0;

        while (pq.Count > 0)
        {
            var (pass, total) = pq.Dequeue();
            res += (double)pass / total;
        }

        return res / classes.Length;
    }
}
