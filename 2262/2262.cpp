class Solution {
public:
    long long appealSum(string s) {
        long long res = 0;
        int lastDig[26];
        memset(lastDig, 0, sizeof(lastDig));
        for(int i = 0; i < s.size(); ++i){
            lastDig[s[i] - 'a'] = i + 1;
            for(int j = 0; j < 26; ++j){
                res += lastDig[j];
            }
        }
        return res;
    }
};