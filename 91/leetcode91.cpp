#include<string>
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1){
            return s[0] == '0' ? 0 : 1;
        }
        vector<int>v(n + 1, 1);
        v[1] = 1 *getValid(s[0], s[0], 0); 
        for(int i = 2; i <= s.size(); ++i){
            char c1 = s[i - 2];
            char c2 = s[i - 1];
            v[i] = getValid(c1, c2, 1) * v[i - 2] + getValid(c1, c2, 0) * v[i - 1];
        }
        return v.back();
    }
private:
    bool getValid(char c1, char c2, int type){
        if(type == 1){
            int dif1 = c1 - '0';
            if(dif1 == 0 || dif1 > 2)return false;
            int dif2 = c2 - '0';
            if(dif1 == 2 && dif2 > 6)return false;
        }else{
            if(c2 == '0')return false;
        }
        return true;
    }
};

int main(){
    Solution * solution = new Solution();
    string s1 = "12";
    int v = solution->numDecodings(s1);
    cout<<v<<endl;


    return 0;
}