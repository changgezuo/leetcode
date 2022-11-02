#include<vector>
#include<queue>

using namespace std;



class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        auto cmp = [](pair<int, int>&a, pair<int, int>&b){
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        int n = growTime.size();
        for(int i = 0; i < n; ++i) {
            pq.push(make_pair(growTime[i], plantTime[i]));
        }
        int res = 0, start = 0;
        while (!pq.empty()) {
            start += pq.top().second;
            res = max(res, start + pq.top().first);
            pq.pop();
        }
        return res;
    }
};

auto main()->int {
    Solution * solution = new Solution();
    vector<int>v1{1,4,3};
    vector<int>v2{2,3,1};
    solution->earliestFullBloom(v1, v2);
    
}