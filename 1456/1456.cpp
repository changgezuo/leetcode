#include<string>
#include<unordered_set>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>dic;
		for(char  c : vowels)dic.insert(c);
		int l = 0, r = k;
		int res = 0, curCnt = 0;
		for(int i = 0; i < k; ++i){
			if (dic.count(s[i]))curCnt++;
		}
		res = curCnt;
		while (r < s.size()){
			if(dic.count(s[r])){
				
			}
		}
    }
private:
    vector<char>vowels{'a', 'e', 'i', 'o', 'u'};
};

auto main () ->int{
	string str1 = "hello world";
    string str2 = str1;
    printf ("Sharing the memory:/n");
    printf ("/tstr1's address: %x/n", str1.c_str() );
    printf ("/tstr2's address: %x/n", str2.c_str() );
    str1[1]='q';
    str2[1]='w';
    printf ("After Copy-On-Write:/n");
    printf ("/tstr1's address: %x/n", str1.c_str() );
    printf ("/tstr2's address: %x/n", str2.c_str() );
    return 0;

	
}