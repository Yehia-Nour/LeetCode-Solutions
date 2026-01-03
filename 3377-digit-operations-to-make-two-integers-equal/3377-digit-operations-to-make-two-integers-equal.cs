public class Solution
{
    public int MinOperations(int n, int m)
    {
        if (IsPrime(n) || IsPrime(m))
            return -1;

        const int MAX = 10000;
        int[] dist = new int[MAX];
        Array.Fill(dist, int.MaxValue);

        var pq = new PriorityQueue<(int cost, int value), int>();

        dist[n] = n;
        pq.Enqueue((n, n), n);

        while (pq.Count > 0)
        {
            var (cost, cur) = pq.Dequeue();

            if (cur == m)
                return cost;

            if (cost > dist[cur])
                continue;

            char[] digits = cur.ToString().ToCharArray();

            for (int i = 0; i < digits.Length; i++)
            {
                char original = digits[i];

                if (digits[i] < '9')
                {
                    digits[i]++;
                    int next = int.Parse(digits);

                    if (!IsPrime(next) && cost + next < dist[next])
                    {
                        dist[next] = cost + next;
                        pq.Enqueue((dist[next], next), dist[next]);
                    }
                }

                digits[i] = original;

                if (digits[i] > '0')
                {
                    digits[i]--;
                    int next = int.Parse(digits);

                    if (!IsPrime(next) && cost + next < dist[next])
                    {
                        dist[next] = cost + next;
                        pq.Enqueue((dist[next], next), dist[next]);
                    }
                }

                digits[i] = original;
            }
        }

        return -1;
    }

    private bool IsPrime(int x)
    {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
}
