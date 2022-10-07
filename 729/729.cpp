#include<vector>
#include<algorithm>

using namespace std;


class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto & a : v){
            if(max(a.first, start) < min(a.second, end))return false;
        }
        v.push_back(make_pair(start, end));
        return true;
    }
private:
    vector<pair<int, int>>v;
};