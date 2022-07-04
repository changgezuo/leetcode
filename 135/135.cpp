class Solution {
public:
    int candy(vector<int>& ratings) {
        queue<int>q;
        int n = ratings.size();
        vector<int>v(n, 0);
        ratings.push_back(INT_MAX);
        for(int i = 0; i < n; ++i){
            if(i == 0){
                if(ratings[i] <= ratings[i + 1]){
                    q.push(i);
                }else{
                    v[i] = 1;
                }
            }else{
                if(ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]){
                    q.push(i);
                }else if(ratings[i] > ratings[i + 1] && ratings[i] > ratings[i - 1]){
                    v[i] = 2;
                }else {
                    v[i] = 1;
                }
            }
        }
        int res = 0;
  
        int level = 1;
        while (!q.empty()){
            int len = q.size();
            res += level * len;
            for(int i = 0; i < len; ++i){
                int cur = q.front();q.pop();
                if(cur - 1 >= 0 && ratings[cur - 1] > ratings[cur]){
                    if( -- v[cur - 1] == 0){
                        q.push(cur - 1);
                    }
                }
                if(cur + 1 < n && ratings[cur + 1] > ratings[cur]){
                    if( -- v[cur + 1] == 0){
                        q.push(cur + 1);
                    }
                }
            }
            level++;   
        }
    return res;
    }
};