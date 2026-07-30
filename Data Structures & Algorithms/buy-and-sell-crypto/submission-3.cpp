class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int bestSellingIndex = 0;
        int bestProfit = 0;
        for (unsigned i = 1; i < prices.size(); ++i) {
            int currProfit = prices[i] - prices[bestSellingIndex];
            if (currProfit > bestProfit) {
                bestProfit = currProfit;
            }

            if (prices[i] < prices[bestSellingIndex]) {
                bestSellingIndex = i;
            }
        }
        return bestProfit;
    }
};
