#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution2 {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size(), m = guesses.size();
        vector<vector<int>>v(n + 1, vector<int>());
        for(auto & edge : edges){
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        int error = m - k, res = 0;
        if(error == m)return n;
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(auto & guess : guesses){
                if(!valid(i, guess[0], guess[1], v)){
                    cnt++;
                    if (cnt > error)break;
                }
            }
            res += cnt >error? 0 : 1;
        }
        return res;
    }
    
    bool valid(int root, int tar, int cur, vector<vector<int>>&v){
        if (cur == tar)return true;
        if(cur == root || v[cur].size() == 0)return false;
        for(int num : v[cur]){
            if(num == tar)return true;
            if(num == root)return false;
            if(valid(root, tar, num, v))return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int>um;
        for(int num : nums)um[num]++;
        vector<vector<int>>res;
        bool all = false;
        while(true){
            for(auto & a : um){
                vector<int>cur;
                if(a.second != 0){
                    all = true;
                    cur.push_back(a.first);
                    a.second--;
                }
                if(all){
                    res.push_back(cur);
                }
            }
            if (!all)break;
            all = false;
        }
        return res;
        
    }
};

int main(){
    vector<int>v{1,3,4,1,2,3,1};
    Solution * solution = new Solution();
    solution->findMatrix(v);
}