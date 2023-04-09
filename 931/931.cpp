#include<vector>
#include<limits.h>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)return 1;
        vector<vector<int>>cnt(n, vector<int>(n, 0));
        for(int j = 0; j < n; ++j)cnt[0][j] = 1;
        for(int i = 1; i < n; ++i){
            int minNum = getMinNumber(matrix[i - 1][0], matrix[i - 1][1]);
            matrix[i][0] += minNum;
            if (minNum == matrix[i - 1][0]){
                cnt[i][0] += cnt[i - 1][0];
            }
            if (minNum == matrix[i - 1][1]){
                cnt[i][0] += cnt[i - 1][1];
            }
            for(int j = 1; j < n - 1; ++j){
                minNum = getMinNumber(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]);
                matrix[i][j] += minNum;
                if (minNum == matrix[i - 1][j - 1]){
                    cnt[i][j] += cnt[i - 1][j - 1];
                }
                if (minNum == matrix[i - 1][j]){
                    cnt[i][j] += cnt[i - 1][j];
                }
                if (minNum == matrix[i - 1][j + 1]){
                    cnt[i][j] += cnt[i - 1][j + 1];
                }
            }
            minNum = getMinNumber(matrix[i - 1][n - 2], matrix[i - 1][n - 1]);
            matrix[i][n - 1] += minNum;
            if (minNum == matrix[i - 1][n - 2]){
                cnt[i][n - 1] += cnt[i - 1][n - 2];
            }
            if (minNum == matrix[i - 1][n - 1]){
                cnt[i][n - 1] += cnt[i - 1][n - 1];
            }
        }
        int minVal = INT_MAX;
        for(int j = 0; j < n; ++j){
            minVal = min(minVal, matrix[n - 1][j]);
        }
        return minVal;

    }

    int getMinNumber(int n1, int n2, int n3 = INT_MAX){
        return min(min(n1, n2), n3);
    }
};

auto main()->int{
    Solution * solution = new Solution();
    vector<vector<int>>v{{2,1,3},{6,5,4},{7,8,9}};
    solution->minFallingPathSum(v);
}