#include<vector>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans(k);
        unordered_map<string,int>freq;
        auto cmp=[](pair<string,int>&a,pair<string,int>&b){
            return a.second>b.second||(a.second==b.second&&a.first<b.first);
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(cmp)>pq(cmp);
        for(auto word:words) freq[word]++;
        for(auto it:freq){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
        for(int i=k-1;i>=0;--i){
            ans[i]=pq.top().first;pq.pop();
        }
        return ans;
    }
};

auto main()->int{
    Solution * solution = new Solution();
    vector<string>v{"i","love","leetcode","i","love","coding"};
    solution->topKFrequent(v, 2);
}