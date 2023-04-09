#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1)return 0;
        int n = arr.size();
        unordered_map<int, set<int>>um;
        for(int i = 0; i < n; ++i){
            um[arr[i]].insert(i);
        }
        vector<bool>vis(n, false);
        queue<int>q{{0}};
        vis[0] = true;
        int ret = 0;
        while(!q.empty()){
            int len = q.size();
            ret++;
            for(int i = 0; i < len; ++i){
                int cur = q.front();q.pop();
                vis[cur] = true;
                set<int>next = um[arr[cur]];
                next.insert(cur - 1);
                next.insert(cur + 1);
                for(int num : next){
                    if (num < 0 || num >= n || vis[num])continue;
                    if(num == n - 1)return ret;
                    vis[num] = true;
                    q.push(num);
                }
                um[arr[cur]]={};
            }
            
        }
        return -1;
    }
};
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1)return 0;
        int n = arr.size();
        unordered_map<int, vector<int>>um;
        for(int i = 0; i < n; ++i){
            um[arr[i]].push_back(i);
        }
        vector<bool>vis(n, false);
        queue<int>q{{0}};
        vis[0] = true;
        int ret = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                int cur = q.front();q.pop();

                vector<int>next = um[arr[cur]];
                next.push_back(cur - 1);
                next.push_back(cur + 1);
                for(int num : next){
                    if (num < 0 || num >= n || vis[num])continue;
                    if(num == n - 1)return ret;
                    vis[num] = true;
                    q.push(num);
                }
                um[arr[cur]]={};
            }
            ret++;
        }
        return -1;
    }
};

auto main()->int{

    vector<int>v{100,-23,-23,404,100,23,23,23,3,404};
    Solution * solution = new Solution();
    solution->minJumps(v);
}