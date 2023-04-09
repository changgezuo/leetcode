#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; ++i)dp[i][0] = i;
        for(int j = 0; j <= n; ++j)dp[0][j] = j;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = min(min(dp[i - 1][j] , dp[i][j - 1]) + 1, dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
            }
        }
        return dp[m][n];

    }
};

auto main()->int{
    string s1 = "horse";
    string s2 = "ros";
    Solution * solution = new Solution();
    solution->minDistance(s1, s2);
}