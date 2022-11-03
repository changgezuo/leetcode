#include<vector>
#include<string>
#include<map>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>um;
        for(string & word : words){
            um[word]++;
        }
        
        int res = 0, center = 0;
        for(auto & [word, cnt] : um){
            string rev = string(rbegin(word), rend(word));
            if(rev == word){
                res += 2 * (cnt /2);
                center |= cnt % 2;
            }else{
                auto it = um.find(rev);
                if (it != um.end()){
                    res += min(cnt, it->second);
                }
            }
        }
        return 2 * res + center ? 2:0;
    }
};

int main(){


    Solution * solution = new Solution();
    vector<string>v{"lc","cl","gg"};
    solution->longestPalindrome(v);

}