class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>us;
        for(int num : nums)us.insert(num);
        int res = 0;
        for(int num : nums){
            if(!us.count(num))continue;
            us.erase(num);
            int suc = num + 1;
            int pre = num - 1;
            while(us.count(suc))us.erase(suc++);
            while(us.count(pre))us.erase(pre--);
            res = max(res, suc - pre - 1);
        }
        return res;
    }
};