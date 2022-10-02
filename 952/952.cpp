#include <vector>
#include <algorithm>
using namespace std;
class DSU {
public:
  DSU(int n): v(n) {
    for (int i = 0; i < n; ++i)
      v[i] = i;
  }
  
  void Union(int x, int y) {
    v[Find(x)] = v[Find(y)];
  }
  
  int Find(int x) {
    if (v[x] != x) v[x] = Find(v[x]);
    return v[x];
  }
private:
  vector<int> v;
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
    }
};