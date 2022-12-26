#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m +1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(word1[i] == word2[j]){
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }else{
                    dp[i + 1] [j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return m + n - dp[m][n] * 2;
    }
};


auto main()->int{
    Solution * solution = new Solution();
    solution->minDistance("sea", 
"eat");
    
}