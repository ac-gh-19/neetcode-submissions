class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp -> two choices at a certain day (sell or buy)
        // greedy where we can always sell for profit
        // reason is that if more profit can be made later by buying stock
        // and selling -> theres no harm in selling at the first profit that w can make
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int priceDiff = prices[i] - prices[i-1];
            if (priceDiff >= 0) {
                profit += priceDiff;
            }

        }
        return profit;
    }

};