#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dif = INT_MAX, res = -1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int cur = nums[i] + nums[j] + nums[k];
                if(dif > abs(cur - target)){
                    dif = abs(cur - target);
                    res = cur;
                }
                if(cur > target)k--;
                else j++;
            }
        }
        return res;        
    }
};