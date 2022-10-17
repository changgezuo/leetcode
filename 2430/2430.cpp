#include<string>
#include<vector>
using namespace std;

class Solution {
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
            
        }
    }
private:
    int dp [4001] = {0};
};