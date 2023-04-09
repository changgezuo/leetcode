#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
            for(int j = i - 1; j >= 0; --j){
                if (s[j] == s[i]){
                    dp[j][i] = max(dp[j][i], dp[j + 1][i - 1] + 2);
                }else{
                    dp[j][i] = max(dp[j + 1][i], max(dp[j][i], dp[j][ i - 1]));
                }
            }
        }
        return dp[0][n - 1];
    }
};

auto main()->int{
    Solution * solution = new Solution();
    solution->longestPalindromeSubseq("cbbd");
}