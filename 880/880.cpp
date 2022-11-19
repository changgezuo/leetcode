#include<string>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int i = 0, n = s.size();
        string cur;
        while(i < n){
            if(isdigit(s[i])){
                int cnt = s[i] - '0';
                while(++i < n && isdigit(s[i])){
                    cnt = cnt* 10 + (s[i] - '0');
                }
                if (cur.size() * cnt >= k){
                    char c = cur[k - (k /cur.size()) * cur.size()];
                    string res;
                    res += c;
                    return res;
                }else{
                    k -= cur.size() * cnt;
                    cur = "";
                }
            }else{
                cur+=s[i++];
            }
        }
    }
};