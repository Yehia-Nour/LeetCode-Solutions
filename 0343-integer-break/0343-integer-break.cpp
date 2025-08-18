const int MAX = 58 + 1;
int memory[MAX];

class Solution {
public:
	int productSum(int n) {
		if (n == 1)
			return 1;

		auto &ret = memory[n];
		if (ret != -1)
			return ret;

		ret = n;
		for (int i = 1; i < n; i++)
			ret = max(ret, i * productSum(n - i));

		return ret;
	}

	int integerBreak(int n) {
		if (n == 2 || n == 3)
			return n-1;

		memset(memory, -1, sizeof(memory));
		return productSum(n);
	}
};
