class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought_stock = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); ++i) {
            int currentProfit = prices[i] - bought_stock;
            maxProfit = max(maxProfit, currentProfit);
            bought_stock = min(bought_stock, prices[i]);
        }

        return maxProfit;
    }
};