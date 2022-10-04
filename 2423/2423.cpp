#include<string>
#include<unordered_map>
#include<map>
using namespace std;


class Solution {
    //time complexity O(n), n is the length of word
public:
    bool equalFrequency(string word) {
        unordered_map<char, int>sta;
        for(char c : word)sta[c]++;
        map<int, int>cnt;
        for(auto & a : sta){
            cnt[a.second]++;
        }
        if(cnt.size() > 2)return false;
        if(cnt.size() == 1){
            auto  a = cnt.begin();
            if(a->first != 1 && a->second != 1){
                return false;
            }
            return true;
        }
        int cnt1 = -1,cnt2 = -1, fre1 = -1, fre2 = -1;
        auto iter = cnt.begin();
        cnt1 = iter->second;
        fre1 = iter->first;
        iter++;
        cnt2 = iter->second;
        fre2 = iter->first;
        if(fre1 == 1){
            if(cnt1 != 1 && (fre2 != 2 || fre2 == 2 && cnt2 != 1)){
                return false;
            }
            return true;
        }else{
            if(cnt2 != 1 || fre2 - fre1 != 1){
                return false;
            }
        }
        return true;
        
    }
};


class Solution2 {
    //time complexity O(nm), n is the length of word, m is average length of dic unordered_map, this method 
    //should be slower than upper method, however is easier to understand
public:
    bool equalFrequency(string word) {
        unordered_map<char, int>um;
        for(char c : word)um[c]++;

        for(char c : word){
            um[c]--;
            unordered_map<int, int>freq;
            for(auto & a : um){
                if(a.second != 0)freq[a.second]++;
            }
            if(freq.size() == 1)return true;
            um[c]++;
        }
        return false;
    }
};

int main(){
    Solution * soultion = new Solution();
    string s1 = "abcdefghijklmnopqrstuvwxyznabcdefghijklmnopqrstuvwxyz";
    soultion->equalFrequency(s1);

    return 0;


}