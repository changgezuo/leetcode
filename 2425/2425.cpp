class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), res = 0;
        if(m % 2 == 0){
            if (n % 2 == 0){
                return 0;
            }
            for (int num : nums1){
                res ^= num;
            }
        }else{
            if(n % 2 == 0){
                for(int num : nums2){
                    res ^= num;
                }
            }else{
                for(int num : nums1){
                    res ^= num;
                }
                for(int num : nums2){
                    res ^= num;
                }
            }
        }
        return res;
    }
};