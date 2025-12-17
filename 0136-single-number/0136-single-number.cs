    public class Solution
    {
        public int SingleNumber(int[] nums)
        {
            Dictionary<int, int> dic = [];

            for (int i = 0; i < nums.Length; i++)
                {
                    if (dic.ContainsKey(nums[i]))
                        dic[nums[i]]++;
                    else
                        dic[nums[i]] = 1;
                }
                
            foreach (var item in dic)
            {
                if (item.Value == 1)
                    return item.Key;
            }

            return -1;
        }
    }