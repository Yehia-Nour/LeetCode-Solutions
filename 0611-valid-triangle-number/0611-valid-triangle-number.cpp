class Solution {
public:
	int BSfindFirst(vector<int> &nums, int start, int val) {
		int end = (int) nums.size() - 1;
        int position = nums.size();

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < val)
				start = mid + 1;
			else
				end = mid - 1, position = mid;
		}
		return position;
	}

	int triangleNumber(vector<int> &nums) {
		int count = 0, n = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 2; i++) {
			int k = i + 2;
			for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
				int first_idx = BSfindFirst(nums, j+1, nums[i] + nums[j]);
                count += first_idx - j - 1;
			}
		}
		return count;
	}
};