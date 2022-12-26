

#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<limits.h>
#include<float.h>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, unordered_set<vector<int>>>um;
        int n = points.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; i < n; ++j){
                double slope = getSlope(points[i], points[j]);
                um[slope].insert(points[i]);
                um[slope].insert(points[j]);
            }
        }
        int maxLen = -1;
        for(auto & cur : um){
            if(cur.second.size() > maxLen){
                maxLen = cur.second.size();
            }
        }
        return maxLen;
    }
private:
    double getSlope(vector<int>&v1, vector<int>&v2){
        if (v1[0] == v2[0])return DBL_MAX;
        return (v1[1] - v2[1])/(v1[0] - v2[0]);
    }
};