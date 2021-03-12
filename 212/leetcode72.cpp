class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        if(m==0)return n;
        if(n==0)return m;
        //vector<vector<int>>dp(m+1,vector<int>(n+1));
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<m+1;++i)dp[i][0]=i;
        for(int j=1;j<n+1;++j)dp[0][j]=j;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                int cost=word1[i-1]==word2[j-1]?0:1;
                dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+cost));
            }
        }
        return dp[m][n];
    }
};