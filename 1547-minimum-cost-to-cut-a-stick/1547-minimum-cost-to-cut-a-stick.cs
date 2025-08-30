    public class Solution
    {
        const int _max = 100 + 1 + 2;
        int[,] _memory = new int[_max, _max];
        int[] _cuts;
        int Cut(int start,  int end)
        {
            if (start +1 == end) 
                return 0;

            if (_memory[start, end] != -1)
                return _memory[start, end];

            _memory[start, end] = int.MaxValue;

            for (int i = start + 1; i < end; i++)
            {
                int left = Cut(start, i);
                int right= Cut(i, end);
                int cutCost = _cuts[end] - _cuts[start];
                _memory[start, end] = int.Min(_memory[start, end], cutCost + left + right);
            }
            return _memory[start, end];
        }
        public int MinCost(int n, int[] cuts)
        {
            List<int> list = new List<int>(cuts);
            list.Add(0);
            list.Add(n);
            list.Sort();

            _cuts = list.ToArray();

            for (int i = 0; i < _max; i++)
                for (int j = 0; j < _max; j++)
                    _memory[i, j] = -1;

            return Cut(0, _cuts.Length - 1);
        }
    }