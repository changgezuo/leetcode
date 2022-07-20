class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_set<string>us1;
        unordered_set<string>us2;
        int ret = 0;
        for(string &word : words){
            if(us1.count(word))ret++;
            else if(us2.count(word))continue;
            else {
                bool can = isValid(s, word);
                if(can){
                    us1.insert(word);
                    ret++;
                }
                else us2.insert(word);
            }
        }
        return ret;
    }
private:
    bool isValid(string &s1, string &s2){
        int p1 = 0, p2 = 0;
        while(p2 < s2.size()){
            if(p1 ==s1.size())return false;
            if(s1[p1]!=s2[p2]){
                p1++;
            }else{
                p2++;
                p1++;
            }
        }
        return true;
    }
};