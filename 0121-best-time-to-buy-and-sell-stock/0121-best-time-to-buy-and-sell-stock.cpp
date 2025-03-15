class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy_price = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); ++i) {
            int currentProfit =  prices[i] - buy_price;
            maxProfit = max(currentProfit, maxProfit);
            buy_price = min(buy_price, prices[i]);
        }

        return maxProfit;

    }
};