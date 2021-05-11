class Solution {
    //simple DFS, for those nodes, we set -1 when begin search, if we find  -1 means cycle
    //if we find 1 ,means it has been searched by previous DFS
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(n, vector<int>());
        for(auto &a : prerequisites) {
            graph[a[0]].push_back(a[1]);
        }
        vis = vector<int>(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!cantFindCycle(i,graph))return false;
        }
        return true;
    }
    bool cantFindCycle(int i, vector<vector<int>>&graph) {
        if(vis[i] == -1)return false;
        if(vis[i] == 1)return true;
        vis[i] =-1;
        for(int nextIndex : graph[i]){
            if(!cantFindCycle(nextIndex, graph))return false;
        }
        vis[i] = 1;
        return true;

    }
private:
    vector<int>vis;
};