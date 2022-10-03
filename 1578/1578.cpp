#include<vector>
#include<string>
#include<cmath>
#include<stack>
using namespace std;


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i = 0, res = 0;
        while(i < n ){
            char c = colors[i];
            int j = i + 1;
            while(j < n && colors[j] == c){
                j++;
            }
            if(j == i + 1){
                i = j;
                continue;
            }
            int maxTaken = -1, sum = 0;
            for(; i < j; ++i){
                sum += neededTime[i];
                maxTaken = max(maxTaken, neededTime[i]);
            }
            res += sum - maxTaken;
        }
        return res;
                
    }
};

class Solution2 {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<int>st;
        int n = colors.size(), res = 0;
        for(int i = 0; i < n; ++i){
            if(!st.empty() && colors[st.top()] == colors[i]){
                if(neededTime[st.top()] < neededTime[i]){
                    res += neededTime[st.top()];
                    st.pop();
                    st.push(i);
                    
                }else{
                    res += neededTime[i];
                }
            }else{
                st.push(i);
            }
        }
         return res; 
    }
};