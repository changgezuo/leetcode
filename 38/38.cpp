#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        for(int i = 2; i <= n; ++i){
            pre = helper(pre);
        }
        return pre;
    }

    string helper(string & pre){
        int n = pre.size();
        int i = 0;
        string res;
        while(i < n){
            int j = i + 1;
            while(j < n && pre[j] == pre[j -1]){
                j++;
            }
            res += to_string(j - i);
            res += pre[i];
            i = j;
        }
        return res;
    }
};

auto main()->int{
    Solution * solution = new Solution();
    for(int i = 1; i <= 30; ++i){
        cout<< solution->countAndSay(i)<<endl;
    }
    
}