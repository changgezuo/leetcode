class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())return 0;
        int m = prices.size();
        vector<int>local(k+1, 0);
        vector<int>global(k+1, 0);
        for(int i = 1; i < m ; ++i) {
            int dif = prices[i] - prices[i - 1];
            for(int j = k; j >= 1;--j) {
                local[j] = max(global[j-1]+max(dif, 0), local[j]+dif);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};