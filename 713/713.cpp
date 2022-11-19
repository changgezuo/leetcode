#include<vector>

using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, res = 0, cur = 1;
        while( r < nums.size()){
            cur*= nums[r];
            while (cur >= k && l <= r){
                cur/= nums[l++];
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }

};

auto main()->int {

    vector<int>v{10,5,2,6};
    Solution * soultion = new Solution();
    soultion->numSubarrayProductLessThanK(v, 100);


}