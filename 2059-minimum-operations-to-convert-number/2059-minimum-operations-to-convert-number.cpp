class Solution {
	bool process(queue<int> &q, vector<bool> &visited, int num, int goal) {
		if (num == goal)
			return true;
		if (0 <= num && num <= 1000 && !visited[num]) {
			visited[num] = true;
			q.push(num);
		}
		return false;
	}
public:
	int minimumOperations(vector<int> &nums, int start, int goal) {
		vector<bool> visited(1001);
		queue<int> q;
		q.push(start);
		visited[start] = 1;

		for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
			while (sz--) {
				int x = q.front();
				q.pop();
				for (int i = 0; i < (int) nums.size(); i++)
					if (process(q, visited, x + nums[i], goal) ||
						process(q, visited, x - nums[i], goal) ||
						process(q, visited, x ^ nums[i], goal))
						return level + 1;
			}
		}
		return -1;
	}
};