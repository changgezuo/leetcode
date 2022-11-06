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
        int minI = -1, minC = 'z'+1;
        for(int i = s.size() - 1; i >= 0 ; --i) {
            if (s[i] < minC){
                minC = s[i];
                minI = i;
            }
        }
        return s.substr(minI) + s.substr(0, minI);
    }
};

int main(){

    Solution * solution = new Solution();
    string s = "enbczfjtvxerzbrvigpl";
    printf("%s\n", solution->orderlyQueue(s, 1));
    cout<<solution->orderlyQueue(s, 1);
}