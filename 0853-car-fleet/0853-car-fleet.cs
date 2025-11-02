public class Solution
{
    public int CarFleet(int target, int[] position, int[] speed)
    {
        if (position.Length == 1)
            return 1;

        List<(int position, int speed)> cars = [];

        for (int i = 0; i < position.Length; i++)
            cars.Add((position[i], speed[i]));

        cars = cars.OrderByDescending(c => c.position).ToList();

        Stack<double> st = [];

        foreach (var car in cars)
        {
            double time = (double)(target - car.position) / car.speed;

            if (st.Count == 0 || time > st.Peek())
                st.Push(time);
        }

        return st.Count;
    }
}