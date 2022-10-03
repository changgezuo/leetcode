#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
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
        DSU * dsu = new DSU(n + 1);
        for(int num : nums){
            int upperLimit = sqrt(num);
            for(int k = 2; k <= upperLimit; ++k){
                if (num % k == 0){
                    dsu->Union(num , k);
                    dsu->Union(num, num/k);
                }
            }
        }
        unordered_map<int, int>um;
        int res = 1;
        for(int num : nums){
            res = max(res, ++um[dsu->Find(num)]);
        }
        return res;
    }
};

int main(){
    




    return 0;
}