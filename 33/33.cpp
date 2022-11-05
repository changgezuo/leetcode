#include<vector>

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