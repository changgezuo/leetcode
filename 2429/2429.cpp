#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    const int N = 30;
    int minimizeXor(int num1, int num2) {
        vector<int>bits1(N, 0);
        int i = 0, cnt1 = 0;
        while(num1 != 0){
            if(num1 & 1){
                cnt1++;
                bits1[i] = 1;
            }
            i++;
            num1 >>= 1;
        }
        int cnt2 = 0;
        while(num2 != 0){
            if(num2 & 1){
                cnt2++;
            }
            num2 >>= 1;
        }
        int cnt = abs(cnt1 - cnt2);
        int res = 0, pow = 1;
        if(cnt1 >= cnt2){
            for(int i = 0; i < N; ++i){
                if(bits1[i] == 1 && cnt-- <= 0){
                    res += pow;
                }
                pow <<= 1;
            }
        }else{
            for(int i = 0; i < N; ++i){
                if(bits1[i] == 0 ){
                    if(--cnt >= 0) res += pow;
                }else{
                    res += pow;
                }
                pow <<= 1;
            }
        }
        return res;
        
    }
};

auto main()->int{
    Solution * solution = new Solution();
    int a = solution->minimizeXor(3, 5);
    int b = a;
}