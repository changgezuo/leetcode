class Solution {
public:
    int dp[5005];
    int change(int amount, vector<int>& coins) {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int coin:coins){
            for(int j=coin;j<=amount;++j){
                dp[j]+=dp[j-coin];
            }
        }
        return dp[amount];
    }
};