#include<string>
#include<set>
using namespace std;


class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size(), cnt = 0;
        for(int i = 0; i < len/ 2; ++i){
            if (vowels.count(s[i]))cnt++;
        }
        for(int i = len/2; i < len; ++i){
            if (vowels.count(s[i]))cnt--;
        }
        return cnt==0;
    }
private:
    set<char>vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};