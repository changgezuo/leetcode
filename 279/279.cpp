#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>
#include<stdio.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, INT_MAX);
        int sq = sqrt(n);

        dp[0] = 0; 
        for(int i = 1; i < n + 1; ++i){
            int limit = sqrt(i);
            for(int j = 1; j <= min(sq, limit); ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

auto main()->int{
    Solution * solution = new Solution();
    printf("%d",solution->numSquares(13));
}