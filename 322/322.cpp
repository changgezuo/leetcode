#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

// bottom up iteratively to get result
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int>dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int coin : coins){
                if (i >= coin && dp[i - coin] != INT_MAX){
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
                }
            }
        }
        return dp[amount]== INT_MAX? -1 : dp[amount];

    }
};


//top down recursively call with memorization
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>>mem(n + 1, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, mem);
        return ans == 1e9 ? -1 : ans;
    }

    int helper(int curIndex, int target, vector<int>& coins, vector<vector<int>>& mem){
        if (curIndex == 0){
            if (target % coins[0] == 0){
                return target/coins[0];
            }
            return 1e9;
        }
        if (mem[curIndex][target] != -1){
            return mem[curIndex][target];
        }
        int res1 = 1e9;
        if (target >= coins[curIndex]){
            res1 = helper(curIndex, target - coins[curIndex], coins, mem) + 1;
        }
        int res2 = helper(curIndex - 1, target, coins, mem);
        return mem[curIndex][target] = min(res1, res2);
    }
};

auto main()->int{

    Solution * solution = new Solution();
    
}