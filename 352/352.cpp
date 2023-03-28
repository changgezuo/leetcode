#include<vector>
#include<map>
#include<set>
#include<iostream>
#include<unordered_map>

using namespace std;

class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(index.count(value))return;
		if(index.count(value - 1) && index.count(value + 1)){
			int start1 = index[value - 1], start2 = index[value + 1];
			vector<int>a = um[start1], b = um[start2];
			a.pop_back();
			a.push_back(b[1]);
			for(int i = start2; i <= b[1]; ++i){
				index[i] = start1;
			}
			um[start1] = a;
			index[value] = start1;
			um.erase(start2);
		}else if(index.count(value - 1)){
			int start1 = index[value - 1];
			vector<int>a = um[start1];
			a.pop_back();
			a.push_back(value);
			index[value] = start1;
			um[start1] = a;
		}else if(index.count(value + 1)){
			int start2 = index[value + 1];
			vector<int>b = um[start2];
			vector<int>newI = {value, b[1]};
			for(int i = start2; i <= b[1]; ++i){
				index[i] = value;
			}
			um[value] = newI;
			index[value] = value;
			um.erase(value + 1);
		}else{
			index[value] = value;
			um[value] = {value, value};
		}
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
		for(auto & a: um){
			res.push_back(a.second);
		}
		return res;
    }
private:
    unordered_map<int, int>index;
	  map<int, vector<int>>um;
};
struct pair_compare final{
    bool operator() (const std::pair<int, int>& left, const std::pair<int, int>& right) const{
        return left.first < right.first;
    }
};
auto main()->int{
    set<pair<int, int>, pair_compare>dic;
    dic.insert({10, 10});
    dic.insert({60, 60});
    dic.insert({30, 70});
    dic.insert({80, 80});
    pair<int, int>p = make_pair(110, 110);
    int a = 1;
    auto it1 = dic.lower_bound(p), it2 = dic.upper_bound(p);
    if(it1 == dic.end()){
        a = 2;
    }
    
    SummaryRanges * summaryRanges = new SummaryRanges();
    summaryRanges->addNum(6);
    summaryRanges->getIntervals();
    summaryRanges->addNum(6);
    summaryRanges->getIntervals();
    summaryRanges->addNum(0);
    summaryRanges->getIntervals();
    summaryRanges->addNum(4);
    summaryRanges->getIntervals();
    summaryRanges->addNum(8);
    summaryRanges->getIntervals();
    summaryRanges->addNum(7);
    summaryRanges->getIntervals();
    summaryRanges->addNum(6);
    summaryRanges->getIntervals();
    summaryRanges->addNum(4);
    summaryRanges->getIntervals();
    summaryRanges->addNum(7);
    summaryRanges->getIntervals();
    summaryRanges->addNum(5);
    summaryRanges->getIntervals();
}

