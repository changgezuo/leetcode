#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution2 {
public:
    int BIT[60001];
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans=0;
        for(int i=nums1.size()-1;i>=0;--i){
            nums1[i]-=nums2[i];
            for(int j=nums1[i]+30000;j<=60000;j+=j&-j)
                ans+=BIT[j];
            for(int j=nums1[i]+30000+diff;j;j-=j&-j)
                ++BIT[j];
        }
        return ans;
    }
};
class Solution {
typedef long long ll;
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        dif = diff;
        int n = nums1.size();
        vector<int>arr(n, 0);
        for(int i = 0; i < n; ++i)arr[i] = nums1[i] - nums2[i];
        helper(arr, 0, n - 1);
        return res;
    }

private:
    void helper (vector<int> & arr, int a, int b){
        if ( a == b)return;
        int mid = a + (b - a) >> 1;
        helper(arr, a, mid);
        helper(arr, mid + 1, b);
        int i = a;
        for(int j = mid + 1; j <= b; ++ j){
            while(i < mid + 1  && arr[i] <= arr[j] + dif){
                i++;
            }
            res += i - a;
        }
        inplace_merge(arr.begin() + a, arr.begin() + mid + 1, arr.begin() + b + 1);
    }

    int dif;
    ll res = 0;
};

auto main()->int{
    Solution * solution = new Solution();
    vector<int>v1{3,2,5}, v2{2,2,1};
    auto res = solution->numberOfPairs(v1, v2, 1);
    cout<<res<<endl;
}