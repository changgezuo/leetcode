#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target, int start = 0, int end = -1) {
        if (end == -1) {
            end = nums.size() - 1;
        }

        if (start > end) {
            return -1;
        }

        int mid = start + (end - start) /2;

        if (nums[mid] == target) return mid;
        if (nums[start] <= nums[mid]) {
            if (nums[start] <= target && target <= nums[mid]) {
                return search(nums, target, start, mid - 1);
            }else {
                return search(nums, target, mid + 1, end);
            }
        }

        if (nums[mid] <= nums[end]) {
            if (nums[mid] <= target && target <= nums[end]) {
                return search(nums, target, mid + 1, end);
            }else {
                return search(nums, target, start , mid - 1);
            }
        }
        return -1;
        
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target, int l = 0, int r = -1) {

        if (r == -1){
            r = nums.size() - 1;
        }
        if (l > r) return -1;
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target)return mid;
        if (nums[l] <= nums[mid]){
            if(target >= nums[l] && target <= nums[mid]){
                return search(nums, target, l, mid - 1);
            }else{
                return search(nums, target, mid + 1, r);
            }
        }

        if (nums[mid] <= nums[r]){
            if (target <= nums[r] && target >= nums[mid + 1]){
                return search(nums, target, mid + 1, r);
            }
            return search(nums, target, l, mid - 1);
        }
        return -1;    
    }
};

auto main()->int{
    vector<int>v{4,5,6,7,0,1,2};
    Solution2 * solution = new Solution2();
    int res = solution->search(v, 0);
    printf("%d", res);    
}