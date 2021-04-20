class Solution {
public:
    //sell[i] means the maximum profit when the last ops of ith day is sell
    //sell[i] = max(buy[i - 1] + price, sell[i - 1])
    //buy[i] means the maximum profit when the last ops of ith day is buy
    //buy[i] = max(rest[i - 1] - price, buy[i - 1])
    //rest[i] means the maximum profit when the last ops of ith day is null 
    //rest[i] = max(sell[i-1],  rest[i-1])
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)return 0;
        int buy = - prices[0], sell = 0, rest = 0;
        for(int i = 1; i < prices.size(); ++i) {
            tie(buy, sell, rest) = make_tuple(max(buy, rest - prices[i]), max(buy + prices[i], sell), max(sell, rest));
        }
        return max(sell, rest);
    }
};