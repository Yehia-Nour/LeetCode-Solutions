const int MAX = 1000 + 1;
int memory[MAX];

vector<vector<int>> books;
int shelfWidth;

int arrange(int idx) {
	if (idx >= (int) books.size())
		return 0;

	auto &ret = memory[idx];
	if (ret != -1)
		return ret;
	ret = INT_MAX;
	int total_width = 0, mx_height = 0;

	for (int k = idx; k < (int) books.size(); k++) {
		total_width += books[k][0];
		mx_height = max(mx_height, books[k][1]);

		if (total_width > shelfWidth)
			break;
		ret = min(ret, mx_height + arrange(k + 1));
	}
	return ret;
}

class Solution {
public:
	int minHeightShelves(vector<vector<int>> &books_, int shelfWidth_) {
		books = books_;
		shelfWidth = shelfWidth_;
		memset(memory, -1, sizeof(memory));
		return arrange(0);
	}
};