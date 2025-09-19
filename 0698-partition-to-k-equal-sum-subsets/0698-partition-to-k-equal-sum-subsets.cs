public class Solution
{
    List<int> _numbers;
    int _k;
    int _target;
    int[] _bucket;

    bool TryPartition(int idx)
    {
        if (idx == _numbers.Count)
            return true;

        for (int i = 0; i < _k; i++)
        {
            if (_bucket[i] + _numbers[idx] > _target)
                continue;

            _bucket[i] += _numbers[idx];
            if (TryPartition(idx + 1))
                return true;
            _bucket[i] -= _numbers[idx];

            if (_bucket[i] == 0)
                break;
        }
        return false;
    }

    public bool CanPartitionKSubsets(int[] nums, int k)
    {
        int sum = nums.Sum();
        if (sum % k != 0) return false;

        _numbers = new List<int>(nums);
        _numbers.Sort((a, b) => b.CompareTo(a)); 

        _k = k;
        _target = sum / k;
        _bucket = new int[k];

        return TryPartition(0);
    }
}
