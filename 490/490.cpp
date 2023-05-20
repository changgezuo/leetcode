#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;



class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& des) {
        int m = maze.size(), n = maze[0].size();
        queue<int>q{{start[0] * n + start[1]}};
        vector<int>dirs{-1, 0, 1, 0, -1};
        unordered_set<int>vis;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            int curX = cur / n,  curY = cur%n;
            if(curX == des[0] && curY == des[1])return true;
            vis.insert(cur);
            for(int i = 0; i < 4; ++i){
                int nx = curX, ny = curY;
                while(nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0){
                    nx += dirs[i];
                    ny += dirs[i + 1];
                }
                nx -= dirs[i];ny -= dirs[i + 1];
                if (!vis.count(nx * n + ny)){
                    q.push(nx * n + ny);
                }
            }
        }
        return false;
    }
};


auto main()->int{
    Solution * solution = new Solution();
    vector<vector<int>>input{{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int>start(2, 0);
    start[1] = 4;
    vector<int>den{2,3};
    solution->hasPath(input, start, den);

}