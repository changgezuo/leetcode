#include<vector>
#include<algorithm>

using namespace std;

class moveEntity{
public:
    int i;
    int row;
    int col;
    moveEntity(int i, int row, int col){
        this->i = i;
        this->row = row;
        this->col = col;
    }
};
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<moveEntity>v;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                moveEntity entity(grid[i][j], i, j);
                v.push_back(entity);
            }
        }
        sort(v.begin(), v.end(), [](moveEntity &a, moveEntity & b){
           return a.i < b.i; 
        });
        for(int i = 0; i < n *n - 1; ++i){
            if(!checkValid(v[i].row, v[i].col, v[i + 1].row, v[i + 1].col)){
                return false;
            }
        }
        return true;
        
    }
    
    bool checkValid(int row1, int col1, int row2, int col2){
        if(abs(row1 - row2) == 1){
            return abs(col1 - col2) == 2;
        }else if(abs(row1-row2) == 2){
            return abs(col1 - col2) == 1;
        }
        return false;
    }
};

auto main()->int{
    vector<vector<int>>testCase = {{24,11,22,17,4},{21,16,5,12,9},{6,23,10,3,18},{15,20,1,8,13},{0,7,14,19,2}};
    Solution * solution = new Solution();
    solution->checkValidGrid(testCase);
}