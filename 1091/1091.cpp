#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        queue<int>q{{0}};
        int res = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                int cur = q.front();q.pop();
                int x = cur /m , y = cur % m;
                vis[x][y] = true;
                if (x == m - 1 && y == n - 1){
                    return res;
                }
                for(int j = 0; j < 8; ++j){
                    int nex = x + dirs[j][0], ney = y + dirs[j][1];
                    if (nex < 0 || nex >= m || ney < 0 || ney >= n || vis[nex][ney] || grid[nex][ney] == 1)continue;
                    q.push(nex * m + ney);
                }
            }
            res++;
        }
        return -1;
    }
private:
    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, { 1, 0}, {1,1}};
};

auto main()->int{
    Solution * solution = new Solution();
    vector<vector<int>>v{{0,1},{1,0}};
    solution->shortestPathBinaryMatrix(v);
}