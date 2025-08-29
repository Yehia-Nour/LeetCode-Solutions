    public class Solution
    {
        int[] arr;
        int k;
        const int MaxN = 500 + 1;
        int[] memory = new int[MaxN];
        private int DP(int index)
        {
            if (index >= arr.Length) return 0;

            if (memory[index] != -1) return memory[index];

            int mx = int.MinValue;
            memory[index] = int.MinValue;


            for (int endIdx = index; endIdx < index + k; endIdx++)
            {
                if (endIdx >= arr.Length) break;

                mx = int.Max(mx, arr[endIdx]);
                int len = endIdx - index + 1;
                memory[index] = int.Max(memory[index], len * mx + DP(endIdx + 1));
            }
            return memory[index];
        }
        public int MaxSumAfterPartitioning(int[] arr, int k)
        {
            this.arr = arr;
            this.k = k;
            Array.Fill(memory, -1);
            return DP(0);
        }
    }