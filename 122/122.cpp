class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>sell(n, 0), hold = sell;
        hold[0] = - prices[0];
        for(int i = 1; i < n; ++i) {
            sell[i] = max(hold[i - 1] + prices[i], sell[i - 1]);
            hold[i] = max(sell[i - 1] - prices[i], hold[i - 1]);
        }
        return sell[n - 1];
    }
};