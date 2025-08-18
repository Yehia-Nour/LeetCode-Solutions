const int MAX = 10000 + 1;
int memory[MAX];

vector<int> cost;

int perfectSquares(int n) {
	if (n <= 0)
		return 0;

	auto &ret = memory[n];
	if (ret != -1)
		return ret;

	ret = INT_MAX;
	for (int i = 1;i * i <= n; ++i)
		ret = min(ret, 1 + perfectSquares(n - i * i));
	
	return ret;
}

class Solution {
public:
	int numSquares(int n) {
		memset(memory, -1, sizeof(memory));
		return perfectSquares(n);
	}
};