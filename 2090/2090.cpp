#include<vector>

using namespace std;

class Solution {
    using ll = long long;
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(); ll sum = 0;
        vector<int>res(n, - 1);
        if (nums.size() < 2 * k + 1){
            return res;
        }
        for(int i = 0; i < 2 *k + 1; ++i){
            sum += nums[i];
        }
        res[k] = sum / ( 2 * k + 1);
        for (int i = k + 1; i < n - k; ++i){
            sum += nums[i + k];
            sum -= nums[i - k - 1];
            res[i] = sum /(2 * k + 1);
        }
        return res;
    }
};

auto main()->int{
    vector<int>v{7,4,3,9,1,8,5,2,6};
    Solution * solution = new Solution();
    solution->getAverages(v, 3);
}