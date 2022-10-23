#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution1 {
public:
    int deleteString(string &s, int index = 0) {
        if (index == s.size())return 0;
        if (dp[index] != 0){
            return dp[index];
        }

        int res = 0;
        bool found = false;
        for(int i = index ; i < index + (s.size() - index)/2; ++i){
            if(dp[i] != 0)continue;
            if(s.substr(index, i + 1 - index) == s.substr(i + 1, i + 1 - index)){
                found = true;
                res = max(res, 1 + deleteString(s, i + 1));
            } 
        }
        if(!found){
            return dp[index] = 1;
        }
        return dp[index] = res;
    }
private:
    int dp [4001] = {0};
};

class Solution {
public:
    int deleteString(string &s, int i = 0) {
        if (dp[i] == 0) {
            dp[i] = 1;
            for (int len = 1; dp[i] <= s.size() - i - len; ++len)
                if (s.compare(i, len, s, i + len, len) == 0)
                    dp[i] = max(dp[i], 1 + deleteString(s, i + len));
        }
        return dp[i];
    }
private:
    int dp [4001] = {0};
};

int main(){
    Solution * solution = new Solution();
    string s = "abcabcdabc";
    cout<<solution->deleteString(s);
}