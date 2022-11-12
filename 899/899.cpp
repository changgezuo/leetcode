#include<string>
#include<algorithm>
#include<iostream>

using namespace std;


class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        char minC = 'z' + 1;
        for(char c : s){
            minC = min(c, minC);
        }
        string res = s;
        for(int i = 0; i < s.size(); ++i){
            if (s[i] == minC){
                res = min(res, s.substr(i) + s.substr(0, i));
            }
        }
        return res;
    }
};

int main(){

    Solution * solution = new Solution();
    string s = "enbczfjtvxerzbrvigpl";
    printf("%s\n", solution->orderlyQueue(s, 1));
    cout<<solution->orderlyQueue(s, 1);
}