#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
    typedef long long ll;
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        auto cmp =[](pair<int, int> & a, pair<int, int> &b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        int fI = candidates, n = costs.size();
        int bI = max(fI - 1, n - candidates - 1);
        for(int i = 0; i < fI; ++i){
            pq.push(make_pair(i, costs[i]));
        }
        for(int i = costs.size() - 1; i > bI; --i){
            pq.push(make_pair(i, costs[i]));
        }
        ll res = 0;
        for(int i = 0; i < k; ++i){
            auto cur = pq.top();pq.pop();
            res += cur.second;
            int index = cur.first;
            if (fI > bI){
                continue;
            }
            if (index < bI){
                pq.push(make_pair(fI, costs[fI]));
                fI++;
            }else if(index > fI){
                pq.push(make_pair(bI, costs[bI]));
                bI--;
            }
        }
        return res;
    }
};

int main(){
    vector<int>v{31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    Solution * solution = new Solution();
    solution->totalCost(v, 11, 2);
}