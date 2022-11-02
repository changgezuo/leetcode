#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            res = max(res, min(height[r], height[l]) * (r - l));
            if (height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return res;
    }
};


//prunning and find all possible positions
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(),i1 = 0, i2 = 0;
        vector<int>forwardArray(n, 0);vector<int>reverseArray(n,0);
        forwardArray[0] = 0;
        reverseArray[0] = n - 1;
        for(int i = 0; i < n; ++i) {
            if (height[i] > height[forwardArray[i1]]){
                forwardArray[++i1] = i;
            }
        }
        for(int i = n - 1; i >= 0; --i){
            if (height[i] > height[reverseArray[i2]]){
                reverseArray[++i2] = i;
            }
        }
        int res = 0;
        for(int i = 0; i <= i1; ++i){
            int cur1 = forwardArray[i];
            for(int j = 0; j <= i2; ++j){
                int cur2 = reverseArray[j];
                if (cur1 >= cur2)break;
                res = max(res, min(height[cur1], height[cur2])*(cur2 - cur1));
            }
        }
        return res;
    }
};


auto main()->int{
    Solution * solution = new Solution();
    vector<int>v{1,8,6,2,5,4,8,3,7};
    solution->maxArea(v);
}