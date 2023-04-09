#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        return 1;
    }
};

auto main()->int{
    vector<vector<int>>v{{1,2},{2,3},{3,4},{1,3}};
    Solution * solution = new Solution();
    solution->eraseOverlapIntervals(v);
}