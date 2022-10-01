#include<string>
#include<unordered_set>
#include<vector>

using namespace std;


//memory search
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;
		return helper(s1, 0 , s2, 0, s3, 0);
    }
	bool helper(string &s1, int p1 ,string &s2, int p2, string &s3, int p3){
	    if(us.count(p1*s3.size()+p2))return false;
		if(p1 == s1.size())return s2.substr(p2) == s3.substr(p3);
		if(p2 == s2.size())return s1.substr(p1) == s3.substr(p3);
		if((s1[p1] == s3[p3]&&helper(s1, p1+1, s2, p2, s3, p3 + 1))||(
		                                    s2[p2] == s3[p3]&&helper(s1, p1, s2, p2 + 1, s3, p3 +1)))
		return true;
		us.insert(p1*s3.size()+p2);
		return false;
	}
private:
    unordered_set<int>us;
};



//dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;
		int m = s1.size(), n = s2.size();
		vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for(int i = 1; i <= m; ++i){
		    dp[i][0] = (dp[i-1][0]&&s1[i-1] == s3[i-1]);
		}
		for(int j = 1; j <= n; ++j){
		    dp[0][j] = (dp[0][j-1]&&s2[j-1] == s3[j-1]);
		}
		for(int i = 1; i <= m; ++i){
		    for(int j = 1; j <= n ; ++j){
			    dp[i][j] = (dp[i-1][j]&&s1[i-1] == s3[i+j-1])||(dp[i][j-1]&&s2[j-1] == s3[i+j-1]);
			}
		}
		return dp[m][n];

	}
};