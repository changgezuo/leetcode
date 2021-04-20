class Solution121 {
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


class Solution122 {
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

class Solution123 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        vector<int>gobal(3);
        vector<int>part(3);
        for(int i=0;i<prices.size()-1;++i){
            int dif=prices[i+1]-prices[i];
            for(int j=2;j>=1;j--){
                part[j]=max(gobal[j-1]+(dif>0?dif:0),part[j]+dif);
                gobal[j]=max(part[j],gobal[j]);
            }
        }
        return gobal[2];
    }
};

class Solution188 {
	//local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

    //global[i][j] = max(local[i][j], global[i - 1][j])，
    //local means the last ops in the ith day and jth ops
	//global means most profit when ith day , jth ops
	//diff means the difference bewteen day[i] and day[i-1];

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


class Solution309 {
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

class Solution714{
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
