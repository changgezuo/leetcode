#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int pre = nums[0], mid = -1;
        bool midF = false;
        for(int i = 1; i < nums.size() ; ++i){
            if(midF && nums[i] > mid){
                return true;
            }
            if(midF && mid < nums[i] && nums[i] > pre){
                mid = nums[i];
            }
            if(!midF && nums[i] > pre){
                midF = true;
                mid = nums[i];
            }
            pre = min(pre, nums[i]);
            
        }
        return false;
    }
};

auto main()->int{


    Solution * solution = new Solution();

    vector<int>v{{20,100,10,12,5,13}};
    cout<<solution->increasingTriplet(v)<<endl;
}