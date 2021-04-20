class Solution {
public:    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>sell(n, 0), hold = sell;
        hold[0] = - prices[0];
        for(int i = 1; i < n; ++i) {
            sell[i] = max(hold[i - 1] + prices[i] - fee, sell[i - 1]);
            hold[i] = max(hold[i - 1], sell[i - 1] - prices[i]);
        }
        return sell[n - 1];
    }
};