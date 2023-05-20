#include<string>
#include<queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rq, dq;
		for(int i = 0; i < senate.size(); ++i){
			if (senate[i] == 'R')rq.push(i);
			else dq.push(i);
		}
		int i = 0, n = senate.size();
		while(true){
			if (i == n) i = 0;
			if (senate[i] == 'R'){
				if(rq.empty())return "Dire";
				if (rq.front() == i){
					if (dq.empty())return "Radiant";
					dq.pop();
					rq.pop();
					rq.push(i);
				}
			}else{
				if(dq.empty())return "Radiant";
				if (dq.front() == i){
					if (rq.empty())return "Dire";
					rq.pop();
					dq.pop();
					dq.push(i);
				}
			}
			i++;
		}
		return "";
    }
};

auto main()->int{
    Solution * solution = new Solution();
    solution->predictPartyVictory("RDD");
}