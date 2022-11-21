#include<vector>
#include<string>
#include <string.h>

#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int mask[26] ;
        memset(mask, 0, sizeof(mask));
        for(char c : p)mask[c - 'a']++;
        int l = 0, r = p.size();
        for(int i = 0; i < r; ++i){
            mask[s[i] - 'a']--;
        }
        r--;
        vector<int>res;
        if(isAnagram(mask))res.push_back(l);
        while(++r < s.size()){
            mask[s[r] - 'a']++;
            mask[s[l++] - 'a']--;
            if(isAnagram(mask))res.push_back(l);
        }
        return res;     
    }

    bool isAnagram(int mask[]){
        for(int i = 0; i < 26; ++i){
            if (mask[i] != 0)return false;
        }
        return true;
    }
};
auto main()->int{

    Solution * solution = new Solution();
    solution->findAnagrams("cbaebabacd", "abc");
}