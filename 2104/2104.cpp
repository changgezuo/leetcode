#include<vector>
#include<stack>
#include<limits.h>
using namespace std;
class Solution {
    typedef long long ll;
public:
    long long subArrayRanges(vector<int>& nums) {
        ll res = 0;
        int len = nums.size();
        stack<int>st;
        for(int i = 0; i < len; ++i){
            int cur = i == len? INT_MAX:nums[i];
            while(!st.empty() && cur < nums[st.top()]){
                st.pop();
            }
        }
    }
};