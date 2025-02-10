class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i] < buy) buy = prices[i];
            else if (prices[i] - buy > res) res = prices[i] - buy;
        }
        return res;
    }
};