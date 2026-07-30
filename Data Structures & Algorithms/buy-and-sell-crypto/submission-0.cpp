class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = 0;
        for (unsigned i = 0; i < prices.size() - 1; ++i) {
            int profit = 0;
            for (unsigned j = i + 1; j < prices.size(); ++j) {
                profit = prices[j] - prices[i];
                if (profit >= bestProfit) {
                    bestProfit = profit;
                }
            }
        }

        return bestProfit;
    }
};
