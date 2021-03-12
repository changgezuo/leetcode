class Trie{
public:
    Trie(){
        isString=false;
        memset(next,0,sizeof(next));
    }
    bool isString;
    Trie*next[26];
    string curStr;
    
};
class Solution {
//Trie and DFS, time complexity O(M*4*3^(L-1)),M is the sum of all grids, L is the
//length of longest string ,space complexity O(max(N,M)),N is the sum of chars in the trie tree 
private:
    vector<string>ret;
    unordered_set<string>us;
    int dirs[5]={-1,0,1,0,-1};
public:
    Trie*root=new Trie();
    void insert(string v){
        Trie*cur=root;
        for(int i=0;i<v.size();++i){
            if(cur->next[v[i]-'a']==nullptr)cur->next[v[i]-'a']=new Trie();
            cur=cur->next[v[i]-'a'];
        }
        cur->isString=true;
        cur->curStr=v;
    }
    void dfs(int x, int y, Trie*cur, vector<vector<bool>>&vis,vector<vector<char>>& board){
        if(cur->isString){
            if(!us.count(cur->curStr)){
                ret.push_back(cur->curStr);
                us.insert(cur->curStr);
            }
        }
        for(int i=0;i<4;++i){
            int xx=dirs[i]+x, yy=dirs[i+1]+y;
            if(xx<0||yy<0||xx>=vis.size()||yy>=vis[0].size()||vis[xx][yy])continue;
            if(cur->next[board[xx][yy]-'a']){
                vis[xx][yy]=true;
                dfs(xx,yy,cur->next[board[xx][yy]-'a'],vis,board);
                vis[xx][yy]=false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size()==0)return {};
        for(string s:words)insert(s);
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(root->next[board[i][j]-'a']){
                    vis[i][j]=true;
                    dfs(i,j,root->next[board[i][j]-'a'],vis,board);
                    vis[i][j]=false;
                }
            }
        }
        return ret;
    }
};
