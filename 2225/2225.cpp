#include<vector>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int>winners;
        unordered_map<int, int>loseCnt;
        for(auto & match : matches){
            winners.insert(match[0]);
            loseCnt[match[1]]++;
        }
        vector<int>noLoseArray;
        vector<int>loseOnceArray;
        vector<vector<int>>res;
        for(auto & winner : winners){
            if (!loseCnt.count(winner)){
                noLoseArray.push_back(winner);
            }
        }
        for (auto & a : loseCnt){
            if (a.second == 1){
                loseOnceArray.push_back(a.first);
            }
        }
        sort(noLoseArray.begin(), noLoseArray.end());
        sort(loseOnceArray.begin(), loseOnceArray.end());
        res.push_back(noLoseArray);
        res.push_back(loseOnceArray);
        return res;
    }
};