const int MAX = 5000 + 1;
int memory[MAX][2][3];
vector<int> prices;

enum {
	NOTHING = 0, SELL = 1, BUY = 2
};

class Solution {
public:
	int trade(int idx, int have_stock, int last_transaction) {
		if (idx == (int) prices.size())
			return 0;

		auto &ret = memory[idx][have_stock][last_transaction];
		if (ret != -1)
			return ret;

		int do_nothing = trade(idx + 1, have_stock, NOTHING);
		int buy = 0, sell = 0;

		if (have_stock)	
			sell = prices[idx] + trade(idx + 1, 0, SELL);
		else if (last_transaction != SELL)
			buy = -prices[idx] + trade(idx + 1, 1, BUY);

		return ret = max(max(buy, sell), do_nothing);
	}

	int maxProfit(const vector<int> &prices_) {
		prices = prices_;
		memset(memory, -1, sizeof(memory));
		return trade(0, 0, NOTHING);
	}
};