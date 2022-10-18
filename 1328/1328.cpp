#include<string>

using namespace std;
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        for(int i = 0; i < len/2; ++i){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        if(len != 1){
            palindrome[len - 1] = 'b';
            return palindrome;
        }
        return "";
    }
};