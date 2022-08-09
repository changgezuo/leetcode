class Solution {
public:
    //time complexity O(n ^2), 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    //time complexity O(n logn), d[i] means the minest last element of i-length of increaing subsquence  
    int lengthOfLIS2(vector<int>& nums){
        int res = 1, n = nums.size();
        vector<int>v(n + 1, 0);
        v[res] = nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i] > v[res])v[++res] = nums[i];
            else{
                int l = 1, r = res, pos = 0;
                while(l <= r){
                    int mid = l + (r - l)/2;
                    if(v[mid] < nums[i]){
                        pos = mid;
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
                v[pos + 1] = nums[i];
            }
        }
        return res;
    }

};