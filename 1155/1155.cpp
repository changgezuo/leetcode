#include<vector>
#include<iostream>
#include<algorithm>


using namespace std;


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= min(i* k, target); ++j){
                for(int m = max(0, j - k) ; m < j; ++m){
                    dp[i][j] = (dp [i - 1][m] + dp[i][j]) % mod;
                }
            }
        }
        return dp[n][target];
    }
private:
    int mod = 1e9 + 7;    
};

int main(){
    Solution * solution = new Solution();
    int res = solution->numRollsToTarget(1, 6, 3);
    cout<< res << endl;
    res = solution->numRollsToTarget(2, 6, 7);
    cout << res <<endl;
    res = solution->numRollsToTarget(30, 30, 500);
    cout << res <<endl;


    return 0;
}