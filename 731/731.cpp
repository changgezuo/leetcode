#include<vector>
#include<map>

using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        deltas[start]++;
        deltas[end]--;
        int cur = 0;
        for(auto & a : deltas){
            cur += a.second;
            if(cur >= 3){
                deltas[start]--;
                deltas[end]++;
                return false;
            }
        }
        return true;
    }
private:
    map<int, int>deltas;
};