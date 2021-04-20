class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost = INT_MAX;
        int ret = 0;
        for(int price : prices) {
            minCost = min(price, minCost);
            ret = max(ret, price - minCost);
        }
        return ret;
    }
};