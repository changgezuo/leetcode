#include<vector>
#include<string>

using namespace std;
class TrieNode{
public:
  TrieNode(){
      isWord = false;
      for(int i = 0; i < 26; ++i){
          child[i] = nullptr;
      }
  }
    
   void insert(string &s, TrieNode * root){
       TrieNode *cur = root;
       for(char c : s){
           if(cur->child[c - 'a'] == nullptr){
               cur->child[c - 'a'] = new TrieNode();
           }
           cur = cur->child[c - 'a'];
       }
       cur->isWord = true;
       
   }
    bool isWord;
    TrieNode * child[26];
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        root = new TrieNode();
        for(string &s : dictionary){
            root->insert(s, root);
        }
        vector<string>res;
        for(string & query : queries){
            if(canTransfer(root, 0, query, 0)){
                res.push_back(query);
            }
        }
        return res;
        
    }
    
    bool canTransfer(TrieNode* cur, int curCnt, string &s, int i){
        if (curCnt > 2)return false;
        if(cur->child[s[i] - 'a'] != nullptr){
             if(i == s.size() - 1){
                 if(cur->child[s[i] - 'a']->isWord){
                     return true;
                 }else{
                     if(curCnt >= 2){
                         return false;
                     }else{
                         for(int j = 0; j < 26; ++j){
                             if(cur->child[j] && cur->child[j]->isWord)return true;
                         }
                         return false;
                     }
                 }
             }else{
                 return canTransfer(cur->child[s[i] - 'a'], curCnt, s, i + 1);
             }    
        }else{
            if (i == s.size() - 1){
                if(curCnt >= 2){
                    return false;
                }else{
                    for(int j = 0; j < 26; ++j){
                        if(cur->child[j] && cur->child[j]->isWord)return true;
                    }
                    return false;
                }
            }else{
                for(int j = 0; j < 26; ++j){
                    if(cur->child[j]){
                        if( canTransfer(cur->child[j], curCnt + 1, s, i + 1)){
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
private:
    TrieNode * root;
};

int main(){
    Solution * solution = new Solution();
    vector<string>v1{"cgtkwr"};
    vector<string>v2{"hfosud","aaxhkp","vkvbua","xhqibo","mgxzer","ybzgvv","fsgkoz"};
    solution->twoEditWords(v1, v2);


}