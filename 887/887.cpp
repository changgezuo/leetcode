//time complexity O(kn^2)
//用状态(k,n)代表鸡蛋和楼层，在x层楼扔下，那么dp(k,n)=1+min(1<=x<=n)(max(dp(k-1,x-1),dp(k,n-x))
class Solution1 {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp (k+1, vector<int>(n+1, 0));
        for(int j=1 ;j<=n ;++j ) dp[1][j]=j;
        for(int i=2; i<=k; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = j;
                for( int k=1; k<j; ++k){
                    dp[i][j]=min(dp[i][j], max(dp[i-1][k-1], dp[i][j-k]) + 1);
                }
            }
        }
        return dp[k][n];
    }
};
//上一种方法超时了，因而我们想去优化它，那么可以看到我们是寻找最优的k，对于dp[i-1][k-1],单调增，对于dp[i][j-k],单调减，
// 那么在这个地方可以使用二分搜索去寻找一个合适的k time complexity O(knlogn)
class Solution2 {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp (k+1, vector<int>(n+1, 0));
        for(int j=1 ;j<=n ;++j ) dp[1][j]=j;
        for(int i=2; i<=k; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = j;
                int left =1 ,right = j;
                while(left <right){
                    int mid = (left+ right)/2;
                    if( dp[i-1][mid-1] < dp[i][j - mid])left =mid+1;
                    else right =mid;
                }
                dp[i][j] = min(dp[i][j], max(dp[i-1][right-1],dp[i][j-right])+1);
            }
        }
        return dp[k][n];
    }
};
//上一种方法仍然很慢，因此我们进一步优化，对于k而言，它的每一次搜索对于新的变大的j而言都在增大，因为dp[i-1][k-1]不变，但是dp[i][j-k]随着
//j的增长而增长，所以k也在变大
// 我们可以直接穷举根据上一次的k time complexity O(kn) （因为内部的while一定是常数级别的）
class Solution3 {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp (k+1, vector<int>(n+1, 0));
        for(int j=1 ;j<=n ;++j ) dp[1][j]=j;
        for(int i=2; i<=k; ++i){
            int s = 1;
            for(int j=1; j<=n; ++j){
                dp[i][j] = j;
                while(s<j&&dp[i-1][s-1]<dp[i][j-s])s++;
                dp[i][j]=min(dp[i][j],max(dp[i-1][s-1], dp[i][j-s])+1);
            }
        }
        return dp[k][n];
    }
};

//接下来就是转换思路的过程，之前我们是(k,n)分别代表鸡蛋和层数，我们利用一个新状态(m,k)分别代表次数和鸡蛋
//那么就是对于状态(m,k)是从状态(m-1,k-1)+1而来，两种情况，鸡蛋碎掉，(m-1,k-1),鸡蛋没碎(m-1,k)
//因此 dp[m][k]=dp[m-1][k-1]+dp[m-1][k]+1;
//time complexity O(klogn)
class Solution4 {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp (n+1, vector<int>(k+1, 0));
        int m = 0;
        while(dp[m][k] < n){
            ++m;
            for(int j=1; j<=k; ++j){
                dp[m][j]=dp[m-1][j-1]+dp[m-1][j]+1;
            }
        }
        return m;
    }
};
//进一步空间优化，因为m的更新只和上一次m有关
//time complexity O(klogn)
//这个方法比上个方法快很多，应该是一维数组取值较快
class Solution5 {
public:
    int superEggDrop(int K, int N) {
        vector<int> dp(K + 1, 0);
        int m = 0;
        for (; dp[K] < N; ++m) {
            for (int i = K; i > 0; --i) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        return m;
    }
};

//最后，有个人算出了通项式
https://leetcode.com/problems/super-egg-drop/discuss/181702/Clear-C%2B%2B-codeRuntime-0-msO(1)-spacewith-explation.No-DPWhat-we-need-is-mathematical-thought!