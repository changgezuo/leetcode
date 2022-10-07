#include<map>
#include<algorithm>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++deltas_[start];
        --deltas_[end];
        int ans = 0;
        int curr = 0;
        for (const auto& kv : deltas_)            
            ans = max(ans, curr += kv.second);
        return ans;
    }
private:
    map<int, int> deltas_;
};