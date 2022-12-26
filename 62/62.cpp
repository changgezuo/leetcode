#include<vector>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>count(m , vector<int>(n, 1));
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                count[i][j] = count[i - 1][j] + count[i ][ j -1];
            }
        }
        return count[m - 1][n - 1];
    }
};